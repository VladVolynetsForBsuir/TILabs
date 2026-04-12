//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "MathUtils.h"

#include <System.SysUtils.hpp>
#include <cstdint>
#include <fstream>
#include <vector>

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	MemoLog->Clear();
    EditR->ReadOnly   = true;
    EditPhi->ReadOnly = true;
	EditKo->ReadOnly  = true;
	BtnEncrypt->Enabled  = false;
    BtnDecrypt->Enabled  = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnBrowseInputClick(TObject *Sender)
{
    if (OpenDialog1->Execute()) {
        EditInputFile->Text  = OpenDialog1->FileName;
        EditOutputFile->Text = ChangeFileExt(OpenDialog1->FileName, L".txt");
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnBrowseOutputClick(TObject *Sender)
{
    if (!EditOutputFile->Text.IsEmpty())
        SaveDialog1->FileName = EditOutputFile->Text;
    if (SaveDialog1->Execute())
        EditOutputFile->Text = SaveDialog1->FileName;
}


bool TForm1::ValidateEncryptParams(uint32_t &p, uint32_t &q, uint32_t &Ks,
                                    uint32_t &r,  uint32_t &phi)
{
    try { p  = EditP->Text.ToInt();  } catch(...) { p  = 0; }
    try { q  = EditQ->Text.ToInt();  } catch(...) { q  = 0; }
    try { Ks = EditKs->Text.ToInt(); } catch(...) { Ks = 0; }

    if (!is_prime((int32_t)p)) {
        Application->MessageBox(L"p должно быть простым числом!", L"Ошибка", MB_ICONERROR);
        EditP->SetFocus(); return false;
    }
    if (!is_prime((int32_t)q)) {
        Application->MessageBox(L"q должно быть простым числом!", L"Ошибка", MB_ICONERROR);
        EditQ->SetFocus(); return false;
    }
    if (p == q) {
        Application->MessageBox(L"p и q должны быть разными числами!", L"Ошибка", MB_ICONERROR);
        return false;
    }

    r   = p * q;
    phi = (p - 1) * (q - 1);

    if (r <= 256 || r >= 65536) {
        String msg = L"r должен находиться в пределах от 256 до 65536. Подберите другие p и q.";
        Application->MessageBox(msg.c_str(), L"Ошибка", MB_ICONERROR);
        return false;
    }

    if (Ks <= 1 || Ks >= phi) {
        Application->MessageBox(L"Kз должен находиться в пределах от 1 до ф(r)", L"Ошибка", MB_ICONERROR);
        return false;
    }

    int32_t x, y;
    int32_t g = extended_evklid((int32_t)Ks, (int32_t)phi, x, y);
    if (g != 1) {
        Application->MessageBox(L"Значения Kз и φ(r) должны быть взаимно простыми", L"Ошибка", MB_ICONERROR);
        return false;
    }
	return true;
}

//---------------------------------------------------------------------------
bool TForm1::ValidateDecryptParams(uint32_t &r, uint32_t &Ks)
{
    try { r  = EditR->Text.ToInt();  } catch(...) { r  = 0; }
    try { Ks = EditKs->Text.ToInt(); } catch(...) { Ks = 0; }

    if (r <= 256 || r >= 65536) {
        Application->MessageBox(L"Модуль r должен быть в диапазоне (256, 65536)", L"Ошибка", MB_ICONERROR);
        EditR->SetFocus(); return false;
    }
    if (Ks <= 1) {
		Application->MessageBox(L"Закрытый ключ Kз должен быть > 1!", L"Ошибка", MB_ICONERROR);
        EditKs->SetFocus(); return false;
    }
    return true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnCalcKeysClick(TObject *Sender)
{
    uint32_t p, q, Ks, r, phi;
    if (!ValidateEncryptParams(p, q, Ks, r, phi)) return;

    int32_t Ko = mod_inverse((int32_t)Ks, (int32_t)phi);
    if (Ko < 0) {
        Application->MessageBox(L"Не удалось вычислить Ko. Проверьте Kз.", L"Ошибка", MB_ICONERROR);
        return;
    }

    EditR->Text   = IntToStr((int)r);
    EditPhi->Text = IntToStr((int)phi);
    EditKo->Text  = IntToStr(Ko);

    BtnEncrypt->Enabled = true;
    BtnDecrypt->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnEncryptClick(TObject *Sender)
{
	if (EditInputFile->Text.IsEmpty()) {
		Application->MessageBox(L"Выберите входной файл!", L"Ошибка", MB_ICONERROR); return;
	}
	if (EditOutputFile->Text.IsEmpty()) {
		Application->MessageBox(L"Укажите выходной файл!", L"Ошибка", MB_ICONERROR); return;
	}

	uint32_t p, q, Ks, r, phi;
	if (!ValidateEncryptParams(p, q, Ks, r, phi)) return;

	int32_t Ko = mod_inverse((int32_t)Ks, (int32_t)phi);//вычисление открытого ключа, инверсного закрытому
	if (Ko < 0) return;

	std::ifstream fin(AnsiString(EditInputFile->Text).c_str(), std::ios::binary);
	if (!fin.is_open()) {
		Application->MessageBox(L"Не удалось открыть входной файл!", L"Ошибка", MB_ICONERROR); return;
	}

	std::ofstream fout(AnsiString(EditOutputFile->Text).c_str(), std::ios::binary);
	if (!fout.is_open()) {
		Application->MessageBox(L"Не удалось создать выходной файл!", L"Ошибка", MB_ICONERROR);
		fin.close(); return;
	}

	std::vector<uint8_t> data((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>()); //создаётся динамический массив data, в который и записывается всё содержимое файла
	fin.close();

	MemoLog->Clear();

	for (size_t i = 0; i < data.size(); i++) {
		uint8_t  m = data[i]; //берём очередной байт из массива
		uint32_t c = mod_pow((uint32_t)m, (uint32_t)Ko, r); //возводим содержимое байта в степень ключа Ко по модулю r

		// Каждый байт преобразуется в 2 байта, которые записываются в выходной файл
		uint16_t block = (uint16_t)c;
		fout.write(reinterpret_cast<const char*>(&block), sizeof(block));

		// Вывод на экран первых 100 блоков в 10-й системе
		if (i < 100) {
			MemoLog->Lines->Add(IntToStr((int)m) + L" -> " + IntToStr((int)c));
		}
	}

	if (data.size() > 100) MemoLog->Lines->Add(L"...");
	MemoLog->Lines->Add(L"Шифрование завершено. Файл сохранен.");
	fout.close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnDecryptClick(TObject *Sender)
{
	if (EditInputFile->Text.IsEmpty()) {
        Application->MessageBox(L"Выберите входной файл!", L"Ошибка", MB_ICONERROR); return;
    }
    if (EditOutputFile->Text.IsEmpty()) {
        Application->MessageBox(L"Укажите выходной файл!", L"Ошибка", MB_ICONERROR); return;
    }

    uint32_t r, Ks;
    if (!ValidateDecryptParams(r, Ks)) return;

    std::ifstream fin(AnsiString(EditInputFile->Text).c_str(), std::ios::binary);
    if (!fin.is_open()) {
        Application->MessageBox(L"Не удалось открыть зашифрованный файл!", L"Ошибка", MB_ICONERROR); return;
    }

    std::ofstream fout(AnsiString(EditOutputFile->Text).c_str(), std::ios::binary);
    if (!fout.is_open()) {
		Application->MessageBox(L"Не удалось создать выходной файл!", L"Ошибка", MB_ICONERROR);
		fin.close(); return;
	}

    uint16_t block;
    int count = 0;
	while (fin.read(reinterpret_cast<char*>(&block), sizeof(block))) //читаем блок размером в 2 байта в переменню block
	{
        uint32_t c = (uint32_t)block;
		uint32_t m = mod_pow(c, Ks, r); //возводим содержимое байта в степень ключа Кз по модулю r
		uint8_t byte_val = (uint8_t)(m & 0xFF); //на всякий случай отсекаем от двухбайтового значения верхний байт (в нормальных условиях не пройдёт, но это для ошибок кодировки

        fout.write(reinterpret_cast<const char*>(&byte_val), 1); //запись 1 байта в выходной файл

        if (count < 100) {
            MemoLog->Lines->Add(IntToStr((int)c) + L" -> " + IntToStr((int)byte_val));
        }
        count++;
    }

    if (count > 100) MemoLog->Lines->Add(L"...");
    MemoLog->Lines->Add(L"Расшифрование завершено.");

    fin.close();
    fout.close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnClearClick(TObject *Sender)
{
    EditP->Clear();  EditQ->Clear();  EditKs->Clear();
    EditR->Clear();  EditPhi->Clear(); EditKo->Clear();
    EditInputFile->Clear();  EditOutputFile->Clear();
    MemoLog->Clear();
    BtnEncrypt->Enabled = false;
    BtnDecrypt->Enabled = false;
}

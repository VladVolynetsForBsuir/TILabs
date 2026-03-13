//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Shifr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// (x^37 + x^12 + x^10 + x^2 + 1)
int reg[37], box_xor[] = {12, 10, 2};
int n = 37, box_count = 3;

// Буферы для данных
unsigned char *file_bytes = NULL;
int file_size = 0;
int *data_bits = NULL;
int *key_bits = NULL;
int *result_bits = NULL;
int bit_count = 0;


int lfsr_step(int reg[], int box_xor[], int n, int box_count)
{
	int out_bit = reg[n - 1];
	int new_bit = reg[n - 1];
	for (int i = 0; i < box_count; i++)
		new_bit = new_bit ^ reg[box_xor[i] - 1];

	for (int i = n - 1; i > 0; i--)
		reg[i] = reg[i - 1];
	reg[0] = new_bit;
	return out_bit;
}

void generate_key(int reg[], int box_xor[], int n, int box_count, int key[], int len)
{
	for (int i = 0; i < len; i++)
		key[i] = lfsr_step(reg, box_xor, n, box_count);
}

void xor_shifr_deshifr(int data[], int key[], int result[], int len)
{
	for (int i = 0; i < len; i++)
		result[i] = data[i] ^ key[i];
}

void bytes_to_bits(unsigned char bytes[], int bits[], int byte_count)
{
	for (int i = 0; i < byte_count; i++)
	{
		int val = bytes[i];
		for (int j = 7; j >= 0; j--)
		{
			bits[i * 8 + j] = val % 2;
			val = val / 2;
		}
	}
}

void bits_to_bytes(int bits[], unsigned char bytes[], int bit_count)
{
	int byte_count = bit_count / 8;
	for (int i = 0; i < byte_count; i++)
	{
		int val = 0;
		for (int j = 0; j < 8; j++)
			val = val * 2 + bits[i * 8 + j];
		bytes[i] = val;
	}
}

AnsiString bits_to_string(int bits[], int len)
{
	AnsiString s;
	for (int i = 0; i < len; i++)
		s = s + AnsiString(bits[i]);
	return s;
}

//проверка на 0/1 при каждом изменении поля начального состояния регистра
void __fastcall TForm1::edtStartRegChange(TObject *Sender)
{
	AnsiString old_text = edtStartReg->Text;
	AnsiString new_text;
	for (int i = 1; i <= old_text.Length(); i++)
		if (old_text[i] == '0' || old_text[i] == '1')
			new_text = new_text + old_text[i];

	if (new_text != old_text)
	{
		edtStartReg->Text = new_text;
		edtStartReg->SelStart = new_text.Length();  // курсор в конец
	}
}


void __fastcall TForm1::btnOpenClick(TObject *Sender)
{
	if (!OpenDialog1->Execute())
		return;

	TFileStream *fs = new TFileStream(OpenDialog1->FileName, fmOpenRead);
	file_size = fs->Size;

	//освобождаем буферы для чтения и выделяем новые
	delete[] file_bytes;
	delete[] data_bits;
	delete[] key_bits;
	delete[] result_bits;

	file_bytes = new unsigned char[file_size];
	bit_count = file_size * 8;
	data_bits = new int[bit_count];
	key_bits = new int[bit_count];
	result_bits = new int[bit_count];

	fs->ReadBuffer(file_bytes, file_size);
	delete fs;

	bytes_to_bits(file_bytes, data_bits, file_size);


	memoSource->Lines->Text = bits_to_string(data_bits, bit_count);
	memoKey->Clear();
	memoResult->Clear();
}


void __fastcall TForm1::btnShifrDeshifrClick(TObject *Sender)
{
	if (file_size == 0)
	{
		ShowMessage(L"Сначала откройте файл");
		return;
	}

	AnsiString seed = edtStartReg->Text;
	if (seed.Length() != n)
	{
		ShowMessage(L"Начальное состояние должно быть 37 бит");
		return;
	}

	for (int i = 0; i < n; i++)
		reg[i] = seed[i + 1] - '0';  // +1 так как AnsiString индексируется с 1

	generate_key(reg, box_xor, n, box_count, key_bits, bit_count);
	xor_shifr_deshifr(data_bits, key_bits, result_bits, bit_count);


	memoKey->Lines->Text = bits_to_string(key_bits, bit_count);
	memoResult->Lines->Text = bits_to_string(result_bits, bit_count);
}


void __fastcall TForm1::btnSaveClick(TObject *Sender)
{
	if (bit_count == 0)
	{
		ShowMessage(L"Нет данных для сохранения!");
		return;
	}

	if (!SaveDialog1->Execute())
		return;

	unsigned char *out_bytes = new unsigned char[file_size];
	bits_to_bytes(result_bits, out_bytes, bit_count);

	TFileStream *fs = new TFileStream(SaveDialog1->FileName, fmCreate);
	fs->WriteBuffer(out_bytes, file_size);
	delete fs;
	delete[] out_bytes;
}


void __fastcall TForm1::btnClearClick(TObject *Sender)
{
	memoKey->Clear();
	memoSource->Clear();
	memoResult->Clear();
	edtStartReg->Clear();

	delete[] file_bytes;  file_bytes = NULL;
	delete[] data_bits;   data_bits = NULL;
	delete[] key_bits;    key_bits = NULL;
	delete[] result_bits; result_bits = NULL;
	file_size = 0;
	bit_count = 0;
}

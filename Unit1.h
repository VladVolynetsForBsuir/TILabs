//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
    // --- Заголовок ---
    TPanel      *PanelTop;
    TLabel      *LabelTitle;

    // --- Параметры (общие для шифрования) ---
    TGroupBox   *GroupParams;
    TLabel      *LabelP;
    TEdit       *EditP;
    TLabel      *LabelQ;
    TEdit       *EditQ;
    TLabel      *LabelKs;
    TEdit       *EditKs;

    // --- Вычисленные значения ---
    TGroupBox   *GroupCalc;
    TLabel      *LabelR;
    TEdit       *EditR;
    TLabel      *LabelPhi;
    TEdit       *EditPhi;
    TLabel      *LabelKo;
    TEdit       *EditKo;

    // --- Кнопка вычисления ключей ---
    TButton     *BtnCalcKeys;

    // --- Файлы ---
    TGroupBox   *GroupFile;
    TLabel      *LabelInputFile;
    TEdit       *EditInputFile;
    TButton     *BtnBrowseInput;
    TLabel      *LabelOutputFile;
    TEdit       *EditOutputFile;
    TButton     *BtnBrowseOutput;

    // --- Кнопки шифрования / расшифрования ---
    TButton     *BtnEncrypt;
    TButton     *BtnDecrypt;
    TButton     *BtnClear;

    // --- Диалоги ---
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
	TMemo *MemoLog;

    // --- Обработчики ---
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BtnBrowseInputClick(TObject *Sender);
    void __fastcall BtnBrowseOutputClick(TObject *Sender);
    void __fastcall BtnCalcKeysClick(TObject *Sender);
    void __fastcall BtnEncryptClick(TObject *Sender);
    void __fastcall BtnDecryptClick(TObject *Sender);
	void __fastcall BtnClearClick(TObject *Sender);

private:
    // Вспомогательные: валидация параметров для шифрования
    bool ValidateEncryptParams(uint32_t &p, uint32_t &q, uint32_t &Ks,
                               uint32_t &r, uint32_t &phi);
    // Вспомогательные: валидация параметров для расшифрования
	bool ValidateDecryptParams(uint32_t &r, uint32_t &Ks);

public:
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

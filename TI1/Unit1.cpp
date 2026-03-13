#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <System.IOUtils.hpp>

#include "Ciphers.h"
#include "Encoding1251.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}


void __fastcall TForm1::btnEncryptClick(TObject *Sender)
{
	std::string input = UnicodeStringToCP1251(memoInput->Lines->Text);
	std::string key   = UnicodeStringToCP1251(edtKey->Text);

	std::string result;
	if (rgCipher->ItemIndex == 0)
		result = Ciphers::VigenereProg_Encrypt(input, key);
	else
		result = Ciphers::Columnar_Encrypt(input, key);

	memoOutput->Lines->Text = CP1251ToUnicodeString(result);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnDecryptClick(TObject *Sender)
{
	std::string shifred = UnicodeStringToCP1251(memoInput->Lines->Text);
	std::string key     = UnicodeStringToCP1251(edtKey->Text);

	std::string result;
	if (rgCipher->ItemIndex == 0)
		result = Ciphers::VigenereProg_Decrypt(shifred, key);
	else
		result = Ciphers::Columnar_Decrypt(shifred, key);

	memoOutput->Lines->Text = CP1251ToUnicodeString(result);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnClearClick(TObject *Sender)
{
	memoInput->Clear();
	memoOutput->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnReadFromFileClick(TObject *Sender)
{
	if (!OpenDialog1->Execute())
        return;

	memoInput->Lines->Text = TFile::ReadAllText(OpenDialog1->FileName, TEncoding::UTF8);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnWriteToFileClick(TObject *Sender)
{

	if (!SaveDialog1->Execute())
		return;
	TFile::WriteAllText(SaveDialog1->FileName, memoOutput->Lines->Text, TEncoding::UTF8);
}

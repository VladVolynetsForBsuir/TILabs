//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TLabel *lblKey;
	TLabel *lblInput;
	TLabel *lblOutput;
	TRadioGroup *rgCipher;
	TEdit *edtKey;
	TMemo *memoInput;
	TMemo *memoOutput;
	TButton *btnReadFromFile;
	TButton *btnDecrypt;
	TButton *btnClear;
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TButton *btnWriteToFile;
	TSaveDialog *SaveDialog1;
	void __fastcall btnEncryptClick(TObject *Sender);
	void __fastcall btnDecryptClick(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);
	void __fastcall btnReadFromFileClick(TObject *Sender);
	void __fastcall btnWriteToFileClick(TObject *Sender);

private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

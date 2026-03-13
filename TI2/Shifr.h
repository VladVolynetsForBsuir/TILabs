//---------------------------------------------------------------------------

#ifndef ShifrH
#define ShifrH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TLabel *lblStartReg;
	TLabel *lblKey;
	TLabel *lblSource;
	TLabel *lblResult;
	TEdit *edtStartReg;
	TMemo *memoKey;
	TMemo *memoSource;
	TMemo *memoResult;
	TButton *btnOpen;
	TButton *btnShifrDeshifr;
	TButton *btnSave;
	TButton *btnClear;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall edtStartRegChange(TObject *Sender);
	void __fastcall btnOpenClick(TObject *Sender);
	void __fastcall btnShifrDeshifrClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);

private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

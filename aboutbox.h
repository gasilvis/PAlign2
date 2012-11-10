//---------------------------------------------------------------------------

#ifndef aboutboxH
#define aboutboxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfAbout : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TButton *Button1;
   TImage *Image1;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TLabel *Label4;
   TLabel *Label5;
   void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TfAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAbout *fAbout;
//---------------------------------------------------------------------------
#endif

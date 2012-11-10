//---------------------------------------------------------------------------

#ifndef helpboxH
#define helpboxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
   TRichEdit *RichEdit1;
   TButton *Button1;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

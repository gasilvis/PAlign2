//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "aboutbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAbout *fAbout;
//---------------------------------------------------------------------------
__fastcall TfAbout::TfAbout(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAbout::Button1Click(TObject *Sender)
{
   Close();   
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "helpbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
/*
   try {
      RichEdit1->Lines->LoadFromFile("palign1.txt");
   } catch (...) {
      ShowMessage("no file");
      Close();
   }
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------


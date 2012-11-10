//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("palign2.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("aboutbox.cpp", fAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
      Application->Initialize();
      Application->CreateForm(__classid(TForm1), &Form1);
      Application->CreateForm(__classid(TfAbout), &fAbout);
      Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------

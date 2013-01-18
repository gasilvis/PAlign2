//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//#include "AdPort.hpp"
//#include "AdWnPort.hpp"
//#include "OoMisc.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
#include "AdPort.hpp"
#include "AdWnPort.hpp"
#include "OoMisc.hpp"
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *Star1Grp;
   TLabel *Label1;
   TLabel *Label2;
   TEdit *S1DD;
   TEdit *S1DM;
   TEdit *S1DS;
   TEdit *S1RH;
   TEdit *S1RM;
   TEdit *S1RS;
   TGroupBox *Star2Grp;
   TLabel *Label3;
   TLabel *Label4;
   TEdit *S2DD;
   TEdit *S2DM;
   TEdit *S2DS;
   TEdit *S2RH;
   TEdit *S2RM;
   TEdit *S2RS;
   TGroupBox *LocationGrp;
   TLabel *Label5;
   TEdit *LatD;
   TEdit *LatM;
   TEdit *LatS;
   TLabel *Label8;
   TLabel *Label9;
   TLabel *Label11;
   TLabel *Label12;
   TLabel *Label13;
   TLabel *Label14;
   TLabel *Label15;
   TLabel *Label16;
   TLabel *Label17;
   TLabel *Label18;
   TLabel *Label19;
   TButton *Button1;
   TButton *Button2;
   TButton *Button3;
   TLabel *Label20;
   TLabel *Label21;
   TLabel *Label24;
   TEdit *errED;
   TEdit *errEM;
   TEdit *errES;
   TLabel *Label25;
   TEdit *errAD;
   TEdit *errAM;
   TEdit *errAS;
   TLabel *Label27;
   TEdit *DTH;
   TEdit *DTM;
   TEdit *DTS;
   TLabel *Label28;
   TEdit *detD;
   TLabel *Label29;
   TEdit *DecRatD;
   TEdit *RARatD;
   TLabel *Label30;
   TLabel *Label31;
   TLabel *Label26;
   TEdit *errRD;
   TEdit *errRM;
   TEdit *errRS;
   TEdit *errDS;
   TEdit *errDM;
   TEdit *errDD;
   TLabel *Label23;
   TPanel *ObsPanel;
   TApdWinsockPort *ApdPort1;
   TCheckBox *TestMode;
   TPanel *LSTPanel;
   TEdit *LSTS;
   TEdit *LSTM;
   TEdit *LSTH;
   TLabel *Label22;
   TButton *Button4;
   TLabel *Label6;
   TButton *Button5;
   TLabel *Label10;
   TButton *StopBtn;
   TEdit *Edit1;
   TEdit *Star1Num;
   TLabel *Star1Name;
   TLabel *Star2Name;
   TEdit *Star2Num;
   TMainMenu *MainMenu1;
   TMenuItem *File1;
   TMenuItem *Exit1;
   TMenuItem *Help1;
   TMenuItem *Help2;
   TMenuItem *About1;
   TLabel *Label7;
   TMemo *Memo1;
   TButton *Button6;
   TButton *Button7;
   TLabel *Label32;
   TLabel *Label33;
   TLabel *Label34;
   TLabel *Label35;
   TGroupBox *SlewErrorGrp;
   TLabel *Label36;
   TLabel *Label37;
   TCSpinEdit *RAMinError;
   TCSpinEdit *DecMinError;
   void __fastcall Star1GrpExit(TObject *Sender);
   void __fastcall NumericOnKeyPress(TObject *Sender, char &Key);
   void __fastcall NumericOnExit(TObject *Sender);
   void __fastcall Star2GrpExit(TObject *Sender);
   void __fastcall LocationGrpExit(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Button2Click(TObject *Sender);
   void __fastcall Button3Click(TObject *Sender);
   void __fastcall ObsPanelExit(TObject *Sender);
   void __fastcall test(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall TestModeClick(TObject *Sender);
   void __fastcall LSTPanelExit(TObject *Sender);
   void __fastcall Button4Click(TObject *Sender);
   void __fastcall Button5Click(TObject *Sender);
   void __fastcall StopBtnClick(TObject *Sender);
   void __fastcall Edit1Exit(TObject *Sender);
   void __fastcall Star1NumExit(TObject *Sender);
   void __fastcall Star2NumExit(TObject *Sender);
   void __fastcall Exit1Click(TObject *Sender);
   void __fastcall About1Click(TObject *Sender);
   void __fastcall Help2Click(TObject *Sender);
   void __fastcall Button6Click(TObject *Sender);
   void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
       __fastcall TForm1(TComponent* Owner);
   int __fastcall SendRcv(char *cmd, char *rsp);
   void __fastcall ShiftError(TObject *Sender, boolean elevation);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

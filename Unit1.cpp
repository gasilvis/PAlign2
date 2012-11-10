//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <inifiles.hpp>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "aboutbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdPort"
#pragma link "AdWnPort"
#pragma link "OoMisc"
#pragma link "AdPort"
#pragma link "AdWnPort"
#pragma link "OoMisc"
#pragma resource "*.dfm"
TForm1 *Form1;

/* packages needed:
VCL50.BPL
A303_R35.BPL
A303_R51.BPL
VCLX50.BPL

*/

/* TKSolver formulas
á1= HMStoD(á1H, á1M, á1S)
Deg=Hours*15+Mins*15/60+Secs*15/3600

ä1= DMStoD(ä1D, ä1M, ä1S)
Deg=(((Secs/60)+Mins)/60)+Degs

DtoHMS
Hours=Int(Deg/15)
Mins= int(((Deg/15)-Hours)*60)
Secs= (   (Deg/15)-(Hours+Mins/60))*3600

DtoDMS
Degs=int(Deg)
Mins=int((Deg-Degs)*60)
Secs=(Deg-(Degs+Mins/60))*3600

det= cosd(Ö)*(tand(ä1) + tand(ä2))*(1-cosd(h1-h2))

RAratio= Äá/Äa

DECratio= Ää/Äe

h1= á1 - LST
h2= á2 - LST
Äá= Äe*(tand(ä2)*sind(h2) - tand(ä1)*sind(h1)) + Äa*cosd(Ö)*(tand(ä1)*cosd(h1) - tand(ä2)*cosd(h2))
Ää= Äe*(cosd(h2)-cosd(h1)) + Äa*cosd(Ö)*(sind(h2)-sind(h1))
Äe= Äá*cosd(Ö)*(sind(h2)-sind(h1))/det - Ää*cosd(Ö)*(tand(ä1)*cosd(h1)-tand(ä2)*cosd(h2))/det
Äa= Äá*(cosd(h1)-cosd(h2))/det + Ää*(tand(ä2)*sind(h2)-tand(ä1)*sind(h1))/det


variables:

Status	Input	Name	Output	Unit	Comment
	3	á1H
	0	á1M
	0	á1S
		á1	45	deg	Right Ascension star 1
		h1	45	deg	Hour Angle star 1
	45	ä1D
	0	ä1M
	0	ä1S
		ä1	45	deg	Declination star 1
	0	á2H
	0	á2M
	0	á2S
		á2	0	deg	Right Ascension star 2
		h2	0	deg	Hour Angle star 2
	45	ä2D
	0	ä2M
	0	ä2S
		ä2	45	deg	Declination star 2
	45	Ö		deg	Site Latitude
	0	LST		deg	Local Sidereal Time
L	100	Äá		min_arc	Error in Right Ascension
	100	Ää		min_arc	Error in Declination
L		Äe	-70.710678	min_arc	Alignment error in elevation (altitude)
L		Äa	-241.42136	min_arc	Alignment error in azimuth

		det	.414213562
		RAratio	-.41421356
		DECratio	-1.4142136
*/

void __fastcall TForm1::NumericOnKeyPress(TObject *Sender, char &Key)
{
   if (! ((Key >= '0' && Key <= '9') || Key == '-' || Key == '.' || Key == '\b'))
      Key = 0 ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::NumericOnExit(TObject *Sender)
{
   TEdit *p;
   float c;
   if((p=dynamic_cast<TEdit*>(Sender))==NULL) return;
   try {
      p->Text= FloatToStr(StrToFloat(p->Text));
   } catch (EConvertError &error) {
      p->Text= FloatToStr(0); // stuff zero on error
   }
}
//---------------------------------------------------------------------------

struct DMS{
   double  deg; // degrees
   double  r;   // radians
   double  D;
   double  M;
   double  S;
};

struct HMS{
   double  deg;
   double  r;   // radians
   double  H;
   double  M;
   double  S;
};
/*  These structures hold 3 versions of angular measurements. If you change one
    version, call one of the functions below to update the alternate forms.
*/
HMS   S1R;        // star 1 Right Ascension
DMS   S1D;        // star 1 declination
HMS   S1H;        // star 1 Hour Angle
HMS   S2R;        // star 2 Right Ascension
DMS   S2D;        // star 2 declination
HMS   S2H;        // star 2 Hour Angle
HMS   S2oR;       // star 2 observed Right Ascension
DMS   S2oD;       // star 2 observed declination
DMS   Lat;        // mount's Latitude
// not necessary DMS   Long;       // mount's Longitude
HMS   LST;        // local sidereal time (at star 2's observation point)
DMS   errD;       // declination error observed at star 2
DMS   errR;       // Right Acension error observed at star 2
DMS   errE;       // mount's estimated elevation error
DMS   errA;       // mount's estimated azimuth error





/* the xMStoD functions are tricky because of the signs. If the lower elements,
   (M and S below D or H) have a different sign from the lead (non-zero) element,
   their sign is taken as relative to the lead sign. So, you can enter -7deg, -30min
   which is -6.5deg and is properly re-expressed as -6deg, 30min.
*/

void _fastcall DtoDMS(DMS *x) {
   int s= 1; long r;
   double dd= x->deg;
   if(dd>180) dd-= 360; // DMS runs 180 to -180;
   long tsecs= floor(0.5+dd*36000); // work with a copy in tenths of an arcsec
   if(tsecs<0) { s= -1; tsecs*= s; } // get sign and shift to postive
   r= tsecs % 36000; x->D= (tsecs-r)/36000; tsecs= r;
   r= tsecs % 600;   x->M= (tsecs-r)/600;
//                     x->S= r/10;
   x->S= ((s*dd)-(x->D+x->M/60))*3600;
   if(x->D) x->D*= s; // apply overall sign
   else if(x->M) x->M*= s;
   else x->S*=s;
   x->r= dd * M_PI/180; // make sure radians are uptodate
}

void _fastcall DMStoD(DMS *x) {
   int s; // sign
   DMS xx= *x; // work with a copy
   if(xx.D) { // extract the sign and go positive
      s= (xx.D<0)?-1:1, xx.D*= s; // use D's sign
   } else { // D is zero
      if(xx.M) s= (xx.M<0)?-1:1, xx.M*= s; // or M's
      else     s= (xx.S<0)?-1:1, xx.S*= s; // or S's
   }
   x->deg= s*((((xx.S/60) + xx.M)/60) + xx.D);
   while(x->deg > 360) x->deg-= 360;
   while(x->deg <   0) x->deg+= 360;
   x->r= x->deg * M_PI/180; // radians
   DtoDMS(x); // reset the DMS
}

void _fastcall DtoHMS(HMS * x) { // set .HMS from .deg
   int s= 1; long r;
   long tsecs= floor(0.5+x->deg*2400); // work with a copy in tenths of a sec
   if(tsecs<0) { s= -1; tsecs*= s; } // get sign and shift to postive
   r= tsecs % 36000; x->H= (tsecs-r)/36000; tsecs= r;
   r= tsecs % 600;   x->M= (tsecs-r)/600;
//                     x->S= r/10;
   x->S= ((s*x->deg/15)-(x->H+x->M/60))*3600; // all the rest
   if(x->H) x->H*= s; // apply overall sign
   else if(x->M) x->M*= s;
   else x->S*=s;
   x->r= x->deg * M_PI/180; // make sure radians are uptodate
}

void _fastcall HMStoD(HMS * x) {
   int s; // sign
   HMS xx= *x;
   if(xx.H) { // extract the sign
      s= (xx.H<0)?-1:1, xx.H*= s; // use H's sign
   } else { // H is zero
      if(xx.M) s= (xx.M<0)?-1:1, xx.M*= s; // or M's
      else     s= (xx.S<0)?-1:1, xx.S*= s; // or S's
   }
   x->deg= s*15*((((xx.S/60)+xx.M)/60)+xx.H);
   while(x->deg > 360) x->deg-= 360;
   while(x->deg <   0) x->deg+= 360;
   x->r= x->deg*M_PI/180; // radians
   DtoHMS(x); // reset the HMS
}



//---------------------------------------------------------------------------

int Star1no= 0, Star2no= 0;
bool ECUavail= false;
FILE *in;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
   // look for star name file
   if((in = fopen("LX334STR.ECU", "rt")) != NULL)  {
      ECUavail= true;
      fclose(in);
   } else { // if not supported, don't show
      Star1Num->Visible= false;
      Star1Name->Visible= false;
      Star2Num->Visible= false;
      Star2Name->Visible= false;
   }

   // open and collect ini data
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   S1D.deg= ini->ReadFloat( "Star1", "Dec", 0.0 );
   DtoDMS(&S1D);
   S1DD->Text= FloatToStrF(S1D.D,ffFixed, 15,0);
   S1DM->Text= FloatToStrF(S1D.M,ffFixed, 15,0);
   S1DS->Text= FloatToStrF(S1D.S,ffFixed, 15,1);
   S1R.deg= ini->ReadFloat( "Star1", "RA", 0.0 );
   DtoHMS(&S1R);
   S1RH->Text= FloatToStrF(S1R.H,ffFixed, 15,0);
   S1RM->Text= FloatToStrF(S1R.M,ffFixed, 15,0);
   S1RS->Text= FloatToStrF(S1R.S,ffFixed, 15,1);

   Star1no= ini->ReadInteger( "Star1", "Number", 0);
   Star1Num->Text= Star1no;
   Star1NumExit(Owner);

   S2D.deg= ini->ReadFloat( "Star2", "Dec", 0.0 );
   DtoDMS(&S2D);
   S2DD->Text= FloatToStrF(S2D.D,ffFixed, 15,0);
   S2DM->Text= FloatToStrF(S2D.M,ffFixed, 15,0);
   S2DS->Text= FloatToStrF(S2D.S,ffFixed, 15,1);
   S2R.deg= ini->ReadFloat( "Star2", "RA", 0.0 );
   DtoHMS(&S2R);
   S2RH->Text= FloatToStrF(S2R.H,ffFixed, 15,0);
   S2RM->Text= FloatToStrF(S2R.M,ffFixed, 15,0);
   S2RS->Text= FloatToStrF(S2R.S,ffFixed, 15,1);

   Star2no= ini->ReadInteger( "Star2", "Number", 0);
   Star2Num->Text= Star2no;
   Star2NumExit(Owner);

   Lat.deg= ini->ReadFloat( "Location", "Lat", 0.0);
   DtoDMS(&Lat);
   LatD->Text= FloatToStrF(Lat.D,ffFixed, 15,0);
   LatM->Text= FloatToStrF(Lat.M,ffFixed, 15,0);
   LatS->Text= FloatToStrF(Lat.S,ffFixed, 15,1);

   ApdPort1->ComNumber= ini->ReadInteger("Setup", "comport", 0);

   delete ini;
   Application->HelpFile= "PAlign2.hlp";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   ApdPort1->Open= false;
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteInteger( "Star1", "Number", Star1no);
   ini->WriteFloat( "Star1", "Dec", S1D.deg);
   ini->WriteFloat( "Star1", "RA", S1R.deg);
   ini->WriteInteger( "Star2", "Number", Star2no);
   ini->WriteFloat( "Star2", "Dec", S2D.deg);
   ini->WriteFloat( "Star2", "RA", S2R.deg);
   ini->WriteFloat( "Location", "Lat", Lat.deg);
   ini->WriteInteger("Setup", "comport", ApdPort1->ComNumber);
   delete ini;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Star1GrpExit(TObject *Sender)
{
   S1R.H= S1RH->Text.ToDouble();
   S1R.M= S1RM->Text.ToDouble();
   S1R.S= S1RS->Text.ToDouble();
   HMStoD(&S1R);
   S1RH->Text= FloatToStrF(S1R.H,ffFixed, 15,0);
   S1RM->Text= FloatToStrF(S1R.M,ffFixed, 15,0);
   S1RS->Text= FloatToStrF(S1R.S,ffFixed, 15,1);
   S1D.D= S1DD->Text.ToDouble();
   S1D.M= S1DM->Text.ToDouble();
   S1D.S= S1DS->Text.ToDouble();
   DMStoD(&S1D);
   S1DD->Text= FloatToStrF(S1D.D,ffFixed, 15,0);
   S1DM->Text= FloatToStrF(S1D.M,ffFixed, 15,0);
   S1DS->Text= FloatToStrF(S1D.S,ffFixed, 15,1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Star2GrpExit(TObject *Sender)
{
   S2R.H= S2RH->Text.ToDouble();
   S2R.M= S2RM->Text.ToDouble();
   S2R.S= S2RS->Text.ToDouble();
   HMStoD(&S2R);
   S2RH->Text= FloatToStrF(S2R.H,ffFixed, 15,0);
   S2RM->Text= FloatToStrF(S2R.M,ffFixed, 15,0);
   S2RS->Text= FloatToStrF(S2R.S,ffFixed, 15,1);

   S2D.D= S2DD->Text.ToDouble();
   S2D.M= S2DM->Text.ToDouble();
   S2D.S= S2DS->Text.ToDouble();
   DMStoD(&S2D);
   S2DD->Text= FloatToStrF(S2D.D,ffFixed, 15,0);
   S2DM->Text= FloatToStrF(S2D.M,ffFixed, 15,0);
   S2DS->Text= FloatToStrF(S2D.S,ffFixed, 15,1);
Edit1->Text= FloatToStrF(S2R.deg, ffFixed, 15,8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LocationGrpExit(TObject *Sender)
{
   Lat.D= LatD->Text.ToDouble();
   Lat.M= LatM->Text.ToDouble();
   Lat.S= LatS->Text.ToDouble();
   DMStoD(&Lat);
   LatD->Text= FloatToStrF(Lat.D,ffFixed, 15,0);
   LatM->Text= FloatToStrF(Lat.M,ffFixed, 15,0);
   LatS->Text= FloatToStrF(Lat.S,ffFixed, 15,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ObsPanelExit(TObject *Sender) // panel
{
   errD.D= errDD->Text.ToDouble();
   errD.M= errDM->Text.ToDouble();
   errD.S= errDS->Text.ToDouble();
   DMStoD(&errD);
   errDD->Text= FloatToStrF(errD.D,ffFixed, 15,0);
   errDM->Text= FloatToStrF(errD.M,ffFixed, 15,0);
   errDS->Text= FloatToStrF(errD.S,ffFixed, 15,1);
   errDD->Hint= errD.deg; errDM->Hint= errD.deg*60; errDS->Hint= errD.deg*3600;

   errR.D= errRD->Text.ToDouble();
   errR.M= errRM->Text.ToDouble();
   errR.S= errRS->Text.ToDouble();
   DMStoD(&errR);
   errRD->Text= FloatToStrF(errR.D,ffFixed, 15,0);
   errRM->Text= FloatToStrF(errR.M,ffFixed, 15,0);
   errRS->Text= FloatToStrF(errR.S,ffFixed, 15,1);
   errRD->Hint= errR.deg; errRM->Hint= errR.deg*60; errRS->Hint= errR.deg*3600;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LSTPanelExit(TObject *Sender)
{
   LST.H= LSTH->Text.ToDouble();
   LST.M= LSTM->Text.ToDouble();
   LST.S= LSTS->Text.ToDouble();
   HMStoD(&LST);
   LSTH->Text= FloatToStrF(LST.H,ffFixed, 15,0);
   LSTM->Text= FloatToStrF(LST.M,ffFixed, 15,0);
   LSTS->Text= FloatToStrF(LST.S,ffFixed, 15,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   // set star1 position
   char s[100], t[100];

   // get site latitude
   // "Gt#", ret "sDD*MM#"  for Lat
   SendRcv(":Gt#", s);
//Label6->Caption= s;
	sscanf(s, "%lf\337%lf#", &Lat.D, &Lat.M); // nb \337 is octal for ascii 223
                                              // which is used for degrees
   Lat.S= 0;
   DMStoD(&Lat);
   LatD->Text= FloatToStrF(Lat.D,ffFixed, 15,0);
   LatM->Text= FloatToStrF(Lat.M,ffFixed, 15,0);
   LatS->Text= FloatToStrF(Lat.S,ffFixed, 15,1);
/*
   // "Gg#", ret "DDD\337MM#"  for Long
   SendRcv(":Gg#", s);
//Label10->Caption= s;
	sscanf(s, "%lf\337%lf#", &Long.D, &Long.M);
   Long.S= 0;
   DMStoD(&Long);
   LongD->Text= FloatToStrF(Long.D,ffFixed, 15,0);
   LongM->Text= FloatToStrF(Long.M,ffFixed, 15,0);
   LongS->Text= FloatToStrF(Long.S,ffFixed, 15,1);
*/
   // confirm long format with "U#"; check return from GD
   SendRcv(":GD#", s);
   if(7==strlen(s)) SendRcv(":U#", NULL);

   // load coord of star 1 and goto
   // ":Sr HH:MM:SS#" ret "1"
   sprintf(t, ":Sr %02.0lf:%02.0lf:%02.0lf#", S1R.H, S1R.M, S1R.S);
//Label10->Caption= t;
   SendRcv(t, NULL);
//Label6->Caption= s;
   // ":Sd sDD*MM:SS#" ret "1"
   sprintf(t, ":Sd %+03.0lf\337%02.0lf:%02.0lf#", S1D.D, S1D.M, S1D.S);
   SendRcv(t, NULL);

   // goto the star 1
//   setSTOPbutton();  // when do we know we're there?  beep?

   // ":MS#", ret "0" (if "1.." or 2..", can't reach it)
   SendRcv(":MS#", NULL);

   ActiveControl= Button2;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   char s[100], t[100];
   // sync to 1, goto star2 position,
   // ":Sr HH:MM:SS#" ret "1"
   // ":Sd sDD*MM:SS#" ret "1"
   // ":CM#", ret "Coordinates     matched.        #"
   SendRcv(":CM#", s);

   // load coord of star 2 and goto
   // ":Sr HH:MM:SS#" ret "1"
   sprintf(t, ":Sr %02.0lf:%02.0lf:%02.0lf#", S2R.H, S2R.M, S2R.S);
   SendRcv(t, NULL);
   // ":Sd sDD*MM:SS#" ret "1"
   sprintf(t, ":Sd %+03.0lf\337%02.0lf:%02.0lf#", S2D.D, S2D.M, S2D.S);
   SendRcv(t, NULL);

   // goto the star 2
//   setSTOPbutton();  // when do we know we're there?  beep?

   // ":MS#", ret "0" (if "1.." or 2..", can't reach it)
   SendRcv(":MS#", NULL);

   ActiveControl= Button3;
}
//---------------------------------------------------------------------------
double det;

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   char s[100], t[100];
   // get star 2 error, compute & display mount errors
   // Get Right Acension ":GR#", ret "HH:MM:SS#"    into S2oR
   if(TestMode->Checked) {
      S2oR= S2R;
      // introduce an error
      S2oR.M+= 1;
   } else {
      SendRcv(":GR#", s);
//Label6->Caption= s;
      sscanf(s, "%lf:%lf:%lf#", &S2oR.H, &S2oR.M, &S2oR.S);
   }
   HMStoD(&S2oR);
   errR.deg= S2oR.deg - S2R.deg;
   DtoDMS(&errR);
   errRD->Text= FloatToStrF(errR.D,ffFixed, 15,0);
   errRM->Text= FloatToStrF(errR.M,ffFixed, 15,0);
   errRS->Text= FloatToStrF(errR.S,ffFixed, 15,1);
   errRD->Hint= errR.deg; errRM->Hint= errR.deg*60; errRS->Hint= errR.deg*3600;
   // Get Declination   ":GD#", ret "sDD*MM:SS#"   into S2oD
   if(TestMode->Checked) {
      S2oD= S2D;
      // introduce an error
      S2oD.D+= 1;
   } else {
      SendRcv(":GD#", s);
//Label10->Caption= s;
      sscanf(s, "%lf\337%lf:%lf#", &S2oD.D, &S2oD.M, &S2oD.S);
   }
   DMStoD(&S2oD);
   errD.deg= S2oD.deg- S2D.deg;
   DtoDMS(&errD);
   errDD->Text= FloatToStrF(errD.D,ffFixed, 15,0);
   errDM->Text= FloatToStrF(errD.M,ffFixed, 15,0);
   errDS->Text= FloatToStrF(errD.S,ffFixed, 15,1);
   errDD->Hint= errD.deg; errDM->Hint= errD.deg*60; errDS->Hint= errD.deg*3600;
   // get LST; do average?
   // Get Sideral Time  ":GS#", ret "HH:MM:SS#"
   if(TestMode->Checked) {
      LST= S2R;
   } else {
      SendRcv(":GS#", s);
      sscanf(s, "%lf:%lf:%lf#", &LST.H, &LST.M, &LST.S);
   }
   HMStoD(&LST);
   LSTH->Text= FloatToStrF(LST.H,ffFixed, 15,0);
   LSTM->Text= FloatToStrF(LST.M,ffFixed, 15,0);
   LSTS->Text= FloatToStrF(LST.S,ffFixed, 15,1);

   // crank the formula
/*
HMS   S1R;        // star 1 Right Ascension
HMS   S2R;        // star 2 Right Ascension
HMS   S1H;        // star 1 Hour Angle
HMS   S2H;        // star 2 Hour Angle
DMS   S1D;        // star 1 declination
DMS   S2D;        // star 2 declination
DMS   Lat;        // mounts Latitude
HMS   LST;        // local sidereal time (at star 2's observation point)
DMS   errD;       // declination error observed at star 2
DMS   errR;       // Right Ascension error observed at star 2
DMS   errE;       // mount's estimated elevation error
DMS   errA;       // mount's estimated azimuth error
*/

   S1H.r= S1R.r - LST.r;
   S2H.r= S2R.r - LST.r;

   det= cos(Lat.r)*(tan(S1D.r) + tan(S2D.r))*(1-cos(S1H.r-S2H.r));
   detD->Text= FloatToStrF(det, ffFixed, 15,8);

   // elevation error
   errE.deg= errR.deg*cos(Lat.r)*(sin(S2H.r)-sin(S1H.r))/det
           - errD.deg*cos(Lat.r)*(tan(S1D.r)*cos(S1H.r)-tan(S2D.r)*cos(S2H.r))/det;
   DtoDMS(&errE);
   errED->Text= FloatToStrF(errE.D,ffFixed, 15,0);
   errEM->Text= FloatToStrF(errE.M,ffFixed, 15,0);
   errES->Text= FloatToStrF(errE.S,ffFixed, 15,1);
   errED->Hint= errE.deg; errEM->Hint= errE.deg*60; errES->Hint= errE.deg*3600;

   // azimuth error
   errA.deg= errR.deg*(cos(S1H.r)-cos(S2H.r))/det
           + errD.deg*(tan(S2D.r)*sin(S2H.r)-tan(S1D.r)*sin(S1H.r))/det;
 Label6->Caption= FloatToStrF(errA.deg,ffFixed, 15, 4);
   DtoDMS(&errA);
 Label10->Caption= FloatToStrF(errA.deg,ffFixed, 15, 4);

   errAD->Text= FloatToStrF(errA.D,ffFixed, 15,0);
   errAM->Text= FloatToStrF(errA.M,ffFixed, 15,0);
   errAS->Text= FloatToStrF(errA.S,ffFixed, 15,1);
   errAD->Hint= errA.deg; errAM->Hint= errA.deg*60; errAS->Hint= errA.deg*3600;
//Label6->Caption= "22";

   DecRatD->Text= FloatToStrF(errE.deg?(errD.deg/errE.deg):0, ffFixed, 15, 8);
   RARatD->Text= FloatToStrF(errA.deg?(errR.deg/errA.deg):0, ffFixed, 15, 8);

   ActiveControl= Button4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   // swap star 1 and star 2
   HMS tempR; DMS tempD; int tempI;

   tempD= S1D; S1D= S2D; S2D= tempD;
   tempR= S1R; S1R= S2R; S2R= tempR;
   tempI= Star1no; Star1no= Star2no; Star2no= tempI;

   S1DD->Text= FloatToStrF(S1D.D,ffFixed, 15,0);
   S1DM->Text= FloatToStrF(S1D.M,ffFixed, 15,0);
   S1DS->Text= FloatToStrF(S1D.S,ffFixed, 15,1);
   S1RH->Text= FloatToStrF(S1R.H,ffFixed, 15,0);
   S1RM->Text= FloatToStrF(S1R.M,ffFixed, 15,0);
   S1RS->Text= FloatToStrF(S1R.S,ffFixed, 15,1);

   Star1Num->Text= Star1no;
   Star1NumExit(Owner);

   S2DD->Text= FloatToStrF(S2D.D,ffFixed, 15,0);
   S2DM->Text= FloatToStrF(S2D.M,ffFixed, 15,0);
   S2DS->Text= FloatToStrF(S2D.S,ffFixed, 15,1);
   S2RH->Text= FloatToStrF(S2R.H,ffFixed, 15,0);
   S2RM->Text= FloatToStrF(S2R.M,ffFixed, 15,0);
   S2RS->Text= FloatToStrF(S2R.S,ffFixed, 15,1);

   Star2Num->Text= Star2no;
   Star2NumExit(Owner);

   ActiveControl= (TestMode->Checked)?Button3:Button2;


//    char s[100];

//    if(SendRcv(":GA#", s))
//       Label6->Caption= s;
//    else       ShowMessage("command error");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::test(TObject *Sender)
{
   S1D.deg= DecRatD->Text.ToDouble();
   DtoDMS(&S1D);
   S1DD->Text= FloatToStrF(S1D.D,ffFixed, 15,0);
   S1DM->Text= FloatToStrF(S1D.M,ffFixed, 15,0);
   S1DS->Text= FloatToStrF(S1D.S,ffFixed, 15,1);

   S1R.deg= RARatD->Text.ToDouble();
   DtoHMS(&S1R);
   S1RH->Text= FloatToStrF(S1R.H,ffFixed, 15,0);
   S1RM->Text= FloatToStrF(S1R.M,ffFixed, 15,0);
   S1RS->Text= FloatToStrF(S1R.S,ffFixed, 15,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopBtnClick(TObject *Sender)
{
   SendRcv(":Q#", NULL);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TestModeClick(TObject *Sender)
{

   if(TestMode->Checked) { // test mode
      ApdPort1->Open= false;
      ApdPort1->ComNumber= 0;
      Button1->Enabled= false;
      Button2->Enabled= false;
      StopBtn->Enabled= false;
      errRD->ReadOnly= false;
      errRM->ReadOnly= false;
      errRS->ReadOnly= false;
      errDD->ReadOnly= false;
      errDM->ReadOnly= false;
      errDS->ReadOnly= false;
      LSTPanel->Enabled= true;
      Star1Grp->Enabled= true;
      Star2Grp->Enabled= true;
      LocationGrp->Enabled= true;
   } else {      // talk to the scope
      ApdPort1->Open= true;
      if(ApdPort1->Open) { // successfully opened
         Button1->Enabled= true;
         Button2->Enabled= true;
         StopBtn->Enabled= true;
         errRD->ReadOnly= true;
         errRM->ReadOnly= true;
         errRS->ReadOnly= true;
         errDD->ReadOnly= true;
         errDM->ReadOnly= true;
         errDS->ReadOnly= true;
         LSTPanel->Enabled= false;
//         Star1Grp->Enabled= false;
//         Star2Grp->Enabled= false;
//         LocationGrp->Enabled= false;
      } else { // failed open
         TestMode->Checked= true;
      }
   }
}
//---------------------------------------------------------------------------
EventTimer ET;
int busy= 0;

int __fastcall TForm1::SendRcv(char *cmd, char *rsp)
{
   int i= 0;
   int done= true;
   char C;


//   while(busy) ;  // attempt to prevent re-entry....
   busy= 1;
   ApdPort1->FlushInBuffer();
   ApdPort1->PutString(cmd);
   Memo1->Lines->Add(cmd);
   if(rsp==NULL) {
      busy= 0; return -1;
   } else {
      NewTimer(ET, 20);
      do {
         ApdPort1->ProcessCommunications();
         Application->ProcessMessages();
         if(ApdPort1->CharReady()) {
            C= ApdPort1->GetChar();
            rsp[i++]= C;
            if(C=='#')
                done= false; // normal end
            if(TimerExpired(ET)) {
               ShowMessage("ET timer expired");
               busy= 0; return 0;
            }
         }
      } while (done);
      rsp[i]= 0;
      busy= 0;
      Memo1->Lines->Add(rsp);
      return(strlen(rsp));
   }
}




void __fastcall TForm1::Button5Click(TObject *Sender)
{
//    SendRcv(":U#", NULL);
//   char t[22];
//   char s[]= "+42z56#";
//   sscanf(s,
//   SendRcv(":Gt#", s);
//Label6->Caption= s;
//	sscanf( s, "%lfz%lf#", &Lat.D, &Lat.M);
//   sprintf(t, ":Sd %+03.0lf\337%02.0lf:%02.0lf#", S1D.D, S1D.M, S1D.S);
//   sprintf(t, ":%02.0lf:%02.0lf:%02.0lf#", S1R.H, S1R.M, S1R.S);
//Label6->Caption= t;

      // ":GR#", ret "HH:MM:SS#"    into S2oR
char s[100];
strcpy(s,"14:15:16#");
//      SendRcv(":GR#", s);
//Label6->Caption= s;
      sscanf(s, "%lf:%lf:%lf#", &S2oR.H, &S2oR.M, &S2oR.S);
  DTH->Text= FloatToStrF(S2oR.H,ffFixed, 15,0);
  DTM->Text= FloatToStrF(S2oR.M,ffFixed, 15,0);
  DTS->Text= FloatToStrF(S2oR.S,ffFixed, 15,1);
      HMStoD(&S2oR);
      errR.deg= S2oR.deg - S2R.deg;
      DtoDMS(&errR);
      errRD->Text= FloatToStrF(errR.D,ffFixed, 15,0);
      errRM->Text= FloatToStrF(errR.M,ffFixed, 15,0);
      errRS->Text= FloatToStrF(errR.S,ffFixed, 15,1);
      errRD->Hint= errR.deg; errRM->Hint= errR.deg*60; errRS->Hint= errR.deg*3600;



}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
   S2R.deg= Edit1->Text.ToDouble();
   DtoHMS(&S2R);
   DTH->Text= FloatToStrF(S2R.H,ffFixed, 15,0);
   DTM->Text= FloatToStrF(S2R.M,ffFixed, 15,0);
   DTS->Text= FloatToStrF(S2R.S,ffFixed, 15,1);
   Edit1->Text= FloatToStrF(S2R.deg,ffFixed,15,8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Star1NumExit(TObject *Sender)
{
// if file exists, validate number, open file, get data
   char s[200], ns[15];
   int i1, i2, i3; float f1, f2, f3;
   int sn;
   // if the file isn't available, don't bother
   if(ECUavail) {
      in= fopen("LX334STR.ECU", "rt");
      // is there a value input?
      try {
         Star1no= Star1Num->Text.ToInt();
         if(Star1no<1) {
            Star1no= 0;
         } else {
            if(Star1no>351) Star1no= 351;
            Star1Num->Text= Star1no;
            for(int i= 0; i<Star1no; i++) fgets(s, 190, in);
            sscanf(s, "%i %f %i %f %i %f %15c", &i1, &f1, &i2, &f2, &i3, &f3, ns);
            S1R.deg= 15.0 * f1;  DtoHMS(&S1R);
            S1RH->Text= FloatToStrF(S1R.H,ffFixed, 15,0);
            S1RM->Text= FloatToStrF(S1R.M,ffFixed, 15,0);
            S1RS->Text= FloatToStrF(S1R.S,ffFixed, 15,1);
            S1D.deg= f2;         DtoDMS(&S1D);
            S1DD->Text= FloatToStrF(S1D.D,ffFixed, 15,0);
            S1DM->Text= FloatToStrF(S1D.M,ffFixed, 15,0);
            S1DS->Text= FloatToStrF(S1D.S,ffFixed, 15,1);
            S1RH->ReadOnly= true; S1RM->ReadOnly= true; S1RS->ReadOnly= true;
            S1DD->ReadOnly= true; S1DM->ReadOnly= true; S1DS->ReadOnly= true;
            i1= 0; while((!isalpha(ns[i1])) && (ns[i1])) i1++;
            Star1Name->Caption= &ns[i1];
         }
      } catch (EConvertError &error) {
         Star1no= 0;
      }
      fclose(in);
   } else {
      Star1no= 0;
   }
   if(!Star1no) {
      Star1Num->Text= ""; Star1Name->Caption= "";
      S1RH->ReadOnly= false; S1RM->ReadOnly= false; S1RS->ReadOnly= false;
      S1DD->ReadOnly= false; S1DM->ReadOnly= false; S1DS->ReadOnly= false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Star2NumExit(TObject *Sender)
{
// if file exists, validate number, open file, get data
   char s[200], ns[15];
   int i1, i2, i3; float f1, f2, f3;
   int sn;
   // if the file isn't available, don't bother
   if(ECUavail) {
      in= fopen("LX334STR.ECU", "rt");
      // is there a value input?
      try {
         Star2no= Star2Num->Text.ToInt();
         if(Star2no<1) {
            Star2no= 0;
         } else {
            if(Star2no>351) Star2no= 351;
            Star2Num->Text= Star2no;
            for(int i= 0; i<Star2no; i++) fgets(s, 190, in);
            sscanf(s, "%i %f %i %f %i %f %15c", &i1, &f1, &i2, &f2, &i3, &f3, ns);
            S2R.deg= 15.0 * f1;  DtoHMS(&S2R);
            S2RH->Text= FloatToStrF(S2R.H,ffFixed, 15,0);
            S2RM->Text= FloatToStrF(S2R.M,ffFixed, 15,0);
            S2RS->Text= FloatToStrF(S2R.S,ffFixed, 15,1);
            S2D.deg= f2;         DtoDMS(&S2D);
            S2DD->Text= FloatToStrF(S2D.D,ffFixed, 15,0);
            S2DM->Text= FloatToStrF(S2D.M,ffFixed, 15,0);
            S2DS->Text= FloatToStrF(S2D.S,ffFixed, 15,1);
            S2RH->ReadOnly= true; S2RM->ReadOnly= true; S2RS->ReadOnly= true;
            S2DD->ReadOnly= true; S2DM->ReadOnly= true; S2DS->ReadOnly= true;
            i1= 0; while((!isalpha(ns[i1])) && (ns[i1])) i1++;
            Star2Name->Caption= &ns[i1];
         }
      } catch (EConvertError &error) {
         Star2no= 0;
      }
      fclose(in);
   } else {
      Star2no= 0;
   }
   if(!Star2no) {
      Star2Num->Text= ""; Star2Name->Caption= "";
      S2RH->ReadOnly= false; S2RM->ReadOnly= false; S2RS->ReadOnly= false;
      S2DD->ReadOnly= false; S2DM->ReadOnly= false; S2DS->ReadOnly= false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::About1Click(TObject *Sender)
{
   fAbout->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Help2Click(TObject *Sender)
{
   Application->HelpJump("Introduction");
}
//---------------------------------------------------------------------------




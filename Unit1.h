//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Media.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Fon;
	TTimer *TimerBtnLeft;
	TTimer *TimerBtnRight;
	TTimer *TimerNewGame;
	TTimer *TimerExit;
	TRectangle *Barrier1;
	TRectangle *Planet1;
	TTimer *TimerPlanet1Up;
	TTimer *TimerPlanet1Down;
	TTimer *TimerBarrier2End;
	TTimer *TimerBarrier2Start;
	TTimer *TimerPlanet2Right;
	TTimer *TimerPlanet2Left;
	TTimer *TimerBarrier1End;
	TTimer *TimerBarrier1Start;
	TTimer *TimerCometa1Move;
	TTimer *TimerCometa1End;
	TRectangle *Planet2;
	TRectangle *Barrier2;
	TRectangle *Star2;
	TRectangle *Star1;
	TRectangle *Cometa1;
	TRectangle *Btn_Armory;
	TRectangle *Btn_Continue;
	TRectangle *Btn_Exit;
	TRectangle *Btn_NewGame;
	TLabel *Label_Btn_Armory;
	TLabel *Label_Btn_Continue;
	TLabel *Label_Btn_Exit;
	TLabel *Label_Btn_NewGame;
	TTimer *TimerStar1End;
	TTimer *TimerStar1Start;
	TTimer *TimerStar1Wait;
	TTimer *TimerBarrier2Wait;
	TTimer *TimerStar2End;
	TTimer *TimerStar2Start;
	TTimer *TimerStar2Wait;
	TTimer *TimerStopAnimation;
	TTimer *TimerStartAnimation;
	TMediaPlayer *MediaPlayer1;
	TTimer *TimerF1MusicRetry;
	TTimer *TimerF1StartMusic;
	TLabel *Label1;
	TFloatAnimation *FloatAnimation1;
	TTimer *TimerLabels;
	TButton *Button1;
	void __fastcall Btn_NewGameClick(TObject *Sender);
	void __fastcall TimerBtnRightTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerBtnLeftTimer(TObject *Sender);
	void __fastcall TimerNewGameTimer(TObject *Sender);
	void __fastcall Btn_ExitClick(TObject *Sender);
	void __fastcall Btn_ArmoryClick(TObject *Sender);
	void __fastcall Btn_ContinueClick(TObject *Sender);
	void __fastcall TimerExitTimer(TObject *Sender);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall TimerPlanet1UpTimer(TObject *Sender);
	void __fastcall TimerPlanet1DownTimer(TObject *Sender);
	void __fastcall TimerPlanet2LeftTimer(TObject *Sender);
	void __fastcall TimerPlanet2RightTimer(TObject *Sender);
	void __fastcall TimerCometa1EndTimer(TObject *Sender);
	void __fastcall TimerCometa1MoveTimer(TObject *Sender);
	void __fastcall TimerBarrier2StartTimer(TObject *Sender);
	void __fastcall TimerBarrier2EndTimer(TObject *Sender);
	void __fastcall TimerBarrier1StartTimer(TObject *Sender);
	void __fastcall TimerBarrier1EndTimer(TObject *Sender);
	void __fastcall TimerStopAnimationTimer(TObject *Sender);
	void __fastcall TimerStartAnimationTimer(TObject *Sender);
	void __fastcall TimerStar1StartTimer(TObject *Sender);
	void __fastcall TimerStar1EndTimer(TObject *Sender);
	void __fastcall TimerStar1WaitTimer(TObject *Sender);
	void __fastcall TimerBarrier2WaitTimer(TObject *Sender);
	void __fastcall TimerStar2WaitTimer(TObject *Sender);
	void __fastcall TimerStar2EndTimer(TObject *Sender);
	void __fastcall TimerStar2StartTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TimerF1MusicRetryTimer(TObject *Sender);
	void __fastcall TimerLabelsTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall TimerF1StartMusicTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

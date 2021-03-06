//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.IOUtils.hpp>
#include <System.SysUtils.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

int F1_BTN_STATE = 0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

void F1_BTN_ANIMATION()
{
	Form1->TimerBtnRight->Enabled = true;
	Form1->TimerBtnLeft->Enabled = true;

	Form1->Btn_Continue->Enabled = false;
	Form1->Btn_Armory->Enabled = false;
	Form1->Btn_Exit->Enabled = false;
	Form1->Btn_NewGame->Enabled = false;
}

void F1_PLANET() //�������, ��������� �.�.�.
{
//Planet1...
	//���������������:
	Form1->Planet1->Position->X = Form1->Width / 2 - Form1->Planet1->Width / 2;
	Form1->Planet1->Position->Y = Form1->Height / 2 - Form1->Planet1->Height / 2;

//Planet2...
	//���������������:
	Form1->Planet2->Position->X = Form1->Width + 250;
	Form1->Planet2->Position->Y = Form1->Height - Form1->Planet2->Height - 50;

//Barrier1...
	//���������������:
	Form1->Barrier1->Position->X = Form1->Width + 250;
	Form1->Barrier1->Position->Y = 5;

//Barrier2...
	//���������������:
	Form1->Barrier2->Position->X = - 50;
	Form1->Barrier2->Position->Y = Form1->Height / 2 - Form1->Barrier2->Height / 2;

//Cometa1...
	//���������������:
	Form1->Cometa1->Position->X = -100;
	Form1->Cometa1->Position->Y = -100;
	Form1->Cometa1->Width = 87;
	Form1->Cometa1->Height = 47;

//Star1...
	//���������������:
	Form1->Star1->Position->X = Form1->Width + 50;
	Form1->Star1->Position->Y = Form1->Height / 2 - Form1->Star1->Height / 2;

//Star2...
	//���������������:
	Form1->Star2->Position->X = - 50;
	Form1->Star2->Position->Y = 15;
}

void F1_RESIZE_COMPONENTS() //������, label's �.�.�.
{
//������.................................
//Continue....
	Form1->Btn_Continue->Position->X = Form1->Width - Form1->Btn_Continue->Width - 4;
	Form1->Btn_Continue->Position->Y = Form1->Height - Form1->Btn_Continue->Height - 4;

	Form1->Label_Btn_Continue->Position->X = Form1->Btn_Continue->Position->X + Form1->Btn_Continue->Width / 2 - Form1->Label_Btn_Continue->Width / 2 + 12; //+12 - ������
	Form1->Label_Btn_Continue->Position->Y = Form1->Btn_Continue->Position->Y + Form1->Btn_Continue->Height / 2 - Form1->Label_Btn_Continue->Height / 2 - 2; // -2 -  ������

//Armory....
	Form1->Btn_Armory->Position->X = Form1->Btn_Continue->Position->X - Form1->Btn_Armory->Width + 22;
	Form1->Btn_Armory->Position->Y = Form1->Height - Form1->Btn_Armory->Height - 4;

	Form1->Label_Btn_Armory->Position->X = Form1->Btn_Armory->Position->X + Form1->Btn_Armory->Width / 2 - Form1->Label_Btn_Armory->Width / 2 + 4; //+4 - ������
	Form1->Label_Btn_Armory->Position->Y = Form1->Btn_Armory->Position->Y + Form1->Btn_Armory->Height / 2 - Form1->Label_Btn_Armory->Height / 2 - 2; // -2 -  ������

//NewGame....
	Form1->Btn_NewGame->Position->X = 4;
	Form1->Btn_NewGame->Position->Y = Form1->Height - Form1->Btn_NewGame->Height - 4;

	Form1->Label_Btn_NewGame->Position->X = Form1->Btn_NewGame->Position->X + Form1->Btn_NewGame->Width / 2 - Form1->Label_Btn_NewGame->Width / 2 - 4; //-4 - ������
	Form1->Label_Btn_NewGame->Position->Y = Form1->Btn_NewGame->Position->Y + Form1->Btn_NewGame->Height / 2 - Form1->Label_Btn_NewGame->Height / 2 - 2; // -2 -  ������

//Exit....
	Form1->Btn_Exit->Position->X = Form1->Btn_NewGame->Position->X + Form1->Btn_Exit->Width + 2;
	Form1->Btn_Exit->Position->Y = Form1->Height - Form1->Btn_NewGame->Height - 4;

	Form1->Label_Btn_Exit->Position->X = Form1->Btn_Exit->Position->X + Form1->Btn_Exit->Width / 2 - Form1->Label_Btn_Exit->Width / 2 + 14; //+12 - ������
	Form1->Label_Btn_Exit->Position->Y = Form1->Btn_Exit->Position->Y + Form1->Btn_Exit->Height / 2 - Form1->Label_Btn_Exit->Height / 2 - 2; // -2 -  ������

//Labels.................................
	Form1->Label1->Position->X = Form1->Width - Form1->Label1->Width - 4;
	Form1->Label1->Position->Y = Form1->Height - Form1->Btn_Continue->Height - 4 - Form1->Label1->Height - 4;
}

void F1_RESET()
{
    F1_BTN_STATE = 0;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_NewGameClick(TObject *Sender)
{
	F1_BTN_ANIMATION();

	F1_BTN_STATE = 4; //������ ����� ������ ���� ������, ��� �� ������������ ��� ��� ���� ������.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBtnRightTimer(TObject *Sender)
{
	if(Form1->Btn_Continue->Position->X < Form1->Width + 200 && Form1->Btn_Armory->Position->X < Form1->Width + 200)
	{
	//Speed x2 / x3
		Form1->Btn_Continue->Position->X++; 	  Form1->Btn_Continue->Position->X++;
		Form1->Label_Btn_Continue->Position->X++; Form1->Label_Btn_Continue->Position->X++; Form1->Label_Btn_Continue->Position->X++;

	//Speed x4
		Form1->Btn_Armory->Position->X++;       Form1->Btn_Armory->Position->X++;       Form1->Btn_Armory->Position->X++;       Form1->Btn_Armory->Position->X++;
		Form1->Label_Btn_Armory->Position->X++; Form1->Label_Btn_Armory->Position->X++; Form1->Label_Btn_Armory->Position->X++; Form1->Label_Btn_Armory->Position->X++;

		if(Form1->Btn_Continue->Position->X >= Form1->Width + 200 || Form1->Btn_Armory->Position->X >= Form1->Width + 200)
		{
			ShowMessage(Btn_Continue->Position->X);
			TimerBtnRight->Enabled = false;
			TimerBtnLeft->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
	F1_RESIZE_COMPONENTS(); //������, label's
	F1_PLANET(); //�������, ��������� �.�.�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
	F1_RESIZE_COMPONENTS();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDeactivate(TObject *Sender)
{
	F1_RESIZE_COMPONENTS();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	F1_RESIZE_COMPONENTS();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBtnLeftTimer(TObject *Sender)
{
	if(Form1->Btn_NewGame->Position->X > - 300 && Form1->Btn_Exit->Position->X > - 300)
	{
	//Speed x2 / x3
		Form1->Btn_NewGame->Position->X--; 	     Form1->Btn_NewGame->Position->X--;       Form1->Btn_NewGame->Position->X--;
		Form1->Label_Btn_NewGame->Position->X--; Form1->Label_Btn_NewGame->Position->X--; Form1->Label_Btn_NewGame->Position->X--;

	//Speed x4
		Form1->Btn_Exit->Position->X--;       Form1->Btn_Exit->Position->X--;       Form1->Btn_Exit->Position->X--;       Form1->Btn_Exit->Position->X--;
		Form1->Label_Btn_Exit->Position->X--; Form1->Label_Btn_Exit->Position->X--; Form1->Label_Btn_Exit->Position->X--; Form1->Label_Btn_Exit->Position->X--;

		if(Form1->Btn_NewGame->Position->X <= - 300 || Form1->Btn_Exit->Position->X <= - 300)
		{
			if(F1_BTN_STATE == 4) //Btn_NewGame
			{
				TimerNewGame->Enabled = true;
			}

			if(F1_BTN_STATE == 3) //Btn_Exit
			{
				TimerExit->Enabled = true;
			}

			TimerBtnRight->Enabled = false;
			TimerBtnLeft->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerNewGameTimer(TObject *Sender)
{
//��������� ������� ������
	TimerNewGame->Enabled = false;

//��������� �������� �������, ��� ��������� ������������������...
	TimerStopAnimation->Enabled = true;

//��������� ������ �� Form1
	TimerF1StartMusic->Enabled = false;
	TimerF1MusicRetry->Enabled = false;
	Form1->MediaPlayer1->Stop();


//�������� ������ �� Form2
	Form2->TimerMusic->Enabled = true;

//������ 3 �����
	Form2->HEALTH->Text = 3;

//���������� ��� �����
	Form2->Health1->Visible = true;
	Form2->Health2->Visible = true;
	Form2->Health3->Visible = true;

	Form2->BtnPlayerJump->Enabled = false;
	Form2->BtnPlayerShield->Enabled = false;

	Form2->TimerGame->Enabled = true;

//��������� ���������� �������������� ��������� ������....
	Form2->TimerStartPosition->Enabled = true;

	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_ExitClick(TObject *Sender)
{
	F1_BTN_ANIMATION();

	F1_BTN_STATE = 3; //������ ����� ������ ���� ������, ��� �� ������������ ��� ��� ���� ������.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_ArmoryClick(TObject *Sender)
{
//	F1_BTN_ANIMATION();
//	F1_BTN_STATE = 2; //������ ����� ������ ���� ������, ��� �� ������������ ��� ��� ���� ������.

	Label1->Visible = true;
	TimerLabels->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_ContinueClick(TObject *Sender)
{
//	F1_BTN_ANIMATION();
//	F1_BTN_STATE = 1; //������ ����� ������ ���� ������, ��� �� ������������ ��� ��� ���� ������.

	Label1->Visible = true;
	TimerLabels->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerExitTimer(TObject *Sender)
{
//��������� ������ �� Form1
	TimerF1StartMusic->Enabled = false;
	TimerF1MusicRetry->Enabled = false;
	Form1->MediaPlayer1->Stop();

//���������
	Close();
	TimerExit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key == vkHardwareBack)
	{
		Key = 0;

		Form1->Btn_ExitClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPlanet1UpTimer(TObject *Sender)
{
	if(Planet1->Width < 175)
	{
		Planet1->Width++;
		Planet1->Height++;

		Planet1->Position->X = Form1->Width / 2 - Planet1->Width / 2;
		Planet1->Position->Y = Form1->Height / 2 - Planet1->Height / 2;

		if(Planet1->Width >= 175)
		{
			TimerPlanet1Down->Enabled = true;
			TimerPlanet1Up->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPlanet1DownTimer(TObject *Sender)
{
	if(Planet1->Width >= 150)
	{
		Planet1->Width--;
		Planet1->Height--;

		Planet1->Position->X = Form1->Width / 2 - Planet1->Width / 2;
		Planet1->Position->Y = Form1->Height / 2 - Planet1->Height / 2;

		if(Planet1->Width <= 150)
		{
			TimerPlanet1Up->Enabled = true;
			TimerPlanet1Down->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPlanet2LeftTimer(TObject *Sender)
{
	if(Planet2->Position->X > - 250)
	{
		Planet2->Position->X--;

		if(Planet2->Position->X <= - 250)
		{
			TimerPlanet2Right->Enabled = true;
			TimerPlanet2Left->Enabled = false;

			Planet2->Position->Y = 5;
			Planet2->Height = 50;
			Planet2->Width = 50;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPlanet2RightTimer(TObject *Sender)
{
	if(Planet2->Position->X < Form1->Width + 250)
	{
		Planet2->Position->X++;

		if(Planet2->Position->X >= Form1->Width + 250)
		{
			TimerPlanet2Right->Enabled = false;
			TimerPlanet2Left->Enabled = true;

			Planet2->Position->Y = Form1->Height - Form1->Planet2->Height - 50;

			Planet2->Height = 100;
			Planet2->Width = 100;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerCometa1EndTimer(TObject *Sender)
{
	Form1->Cometa1->Position->X = -100;
	Form1->Cometa1->Position->Y = -100;
	Form1->Cometa1->Width = 87;
	Form1->Cometa1->Height = 47;

	TimerCometa1Move->Enabled = true;
	TimerCometa1End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerCometa1MoveTimer(TObject *Sender)
{
	if(Cometa1->Position->X < Form1->Width)
	{
		Cometa1->Position->X++; Cometa1->Position->X++;
		Cometa1->Position->Y++;

		Cometa1->Height++;
		Cometa1->Width++;

		if(Cometa1->Position->X >= Form1->Width)
		{
			TimerCometa1End->Enabled = true;
			TimerCometa1Move->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBarrier2StartTimer(TObject *Sender)
{
	if(Barrier2->Position->X < Form1->Width + 50)
	{
		Barrier2->Position->X++; Barrier2->Position->X++; Barrier2->Position->X++; Barrier2->Position->X++;

		if(Barrier2->Position->X >= Form1->Width + 50)
		{
			TimerBarrier2Start->Enabled = false;

			TimerBarrier2End->Interval = Random(15000);
			TimerBarrier2End->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBarrier2EndTimer(TObject *Sender)
{
	Form1->Barrier2->Position->X = - 50;
	Form1->Barrier2->Position->Y = Random(Form1->Height - 50);

	TimerBarrier2Start->Enabled = true;
	TimerBarrier2End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBarrier1StartTimer(TObject *Sender)
{
	if(Barrier1->Position->X > - 250)
	{
		Barrier1->Position->X--;

		if(Barrier1->Position->X <= - 250)
		{
			TimerBarrier1Start->Enabled = false;

			TimerBarrier1End->Interval = Random(20000);
			TimerBarrier1End->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBarrier1EndTimer(TObject *Sender)
{
	Form1->Barrier1->Position->X = Form1->Width + 250;
	Form1->Barrier1->Position->Y = Random(Form1->Height - Form1->Barrier1->Height);

	TimerBarrier1Start->Enabled = true;
	TimerBarrier1End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStopAnimationTimer(TObject *Sender)
{
	TimerCometa1End->Enabled = false;
	TimerCometa1Move->Enabled = false;

	TimerBarrier1Start->Enabled = false;
	TimerBarrier1End->Enabled = false;

	TimerStar2Wait->Enabled = false;
	TimerStar2End->Enabled = false;
	TimerStar2Start->Enabled = false;

	TimerStar1Wait->Enabled = false;
	TimerStar1Start->Enabled = false;
	TimerStar1End->Enabled = false;

	TimerPlanet1Up->Enabled = false;
	TimerPlanet1Down->Enabled = false;

	TimerBarrier2Wait->Enabled = false;
	TimerBarrier2End->Enabled = false;
	TimerBarrier2Start->Enabled = false;

	TimerPlanet2Left->Enabled = false;
	TimerPlanet2Right->Enabled = false;

	TimerStopAnimation->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStartAnimationTimer(TObject *Sender)
{
	F1_PLANET();

//������
	TimerPlanet1Up->Enabled = true;

//Planet2
	TimerPlanet2Left->Enabled = true;

//Cometa
	TimerCometa1Move->Enabled = true;

//Stars
	TimerStar1Wait->Enabled = true;
	TimerStar2Wait->Enabled = true;

//Asterids
	TimerBarrier1Start->Enabled = true;
	TimerBarrier2Wait->Enabled = true;

//����. ������.
	TimerStartAnimation->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar1StartTimer(TObject *Sender)
{
	if(Star1->Position->X > - 50)
	{
		Star1->Position->X--; Star1->Position->X--; Star1->Position->X--; Star1->Position->X--;
		Star1->Position->X--; Star1->Position->X--; Star1->Position->X--; Star1->Position->X--;
		Star1->Position->Y++;

		if(Star1->Position->X <= - 50)
		{
			TimerStar1End->Enabled = true;
			TimerStar1Start->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar1EndTimer(TObject *Sender)
{
	Form1->Star1->Position->X = Form1->Width + 50;
	Form1->Star1->Position->Y = Random(Form1->Height - 50);

	TimerStar1Start->Enabled = true;
	TimerStar1End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar1WaitTimer(TObject *Sender)
{
	TimerStar1Start->Enabled = true;
	TimerStar1Wait->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBarrier2WaitTimer(TObject *Sender)
{
	TimerBarrier2Start->Enabled = true;
	TimerBarrier2Wait->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar2WaitTimer(TObject *Sender)
{
	TimerStar2Start->Enabled = true;
	TimerStar2Wait->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar2EndTimer(TObject *Sender)
{
	Form1->Star2->Position->X = - 50;
	Form1->Star2->Position->Y = Random(Form1->Height - 50);

	TimerStar2Start->Enabled = true;
	TimerStar2End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStar2StartTimer(TObject *Sender)
{
	if(Star2->Position->X < Form1->Width + 50)
	{
		Star2->Position->X++; Star2->Position->X++; Star2->Position->X++; Star2->Position->X++;
		Star2->Position->X++; Star2->Position->X++; Star2->Position->X++; Star2->Position->X++;
		Star2->Position->X++; Star2->Position->X++; Star2->Position->X++; Star2->Position->X++;
		Star2->Position->X++; Star2->Position->X++; Star2->Position->X++; Star2->Position->X++;
		Star2->Position->X++; Star2->Position->X++; Star2->Position->X++; Star2->Position->X++;

		if(Star2->Position->X >= Form1->Width + 50)
		{
			TimerStar2Start->Enabled = false;

			TimerStar2End->Interval = Random(15000);
			TimerStar2End->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TimerF1StartMusic->Enabled = true;

	TimerStartAnimation->Enabled = true;

	Label1->Visible = false;
	Button1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerF1MusicRetryTimer(TObject *Sender)
{
	TimerF1StartMusic->Enabled = true;
	TimerF1MusicRetry->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerLabelsTimer(TObject *Sender)
{
	if(Label1->Visible == true) { Label1->Visible = false; }

	TimerLabels->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	MediaPlayer1->FileName = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "Form1.mp3";
	MediaPlayer1->Play();

	TimerF1StartMusic->Enabled = false;
	TimerF1MusicRetry->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerF1StartMusicTimer(TObject *Sender)
{
	Button1Click(Sender); //�.�. ����� ������ ������� �� ����������

	TimerF1StartMusic->Enabled = false;
}
//---------------------------------------------------------------------------


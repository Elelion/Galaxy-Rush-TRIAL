//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.IOUtils.hpp>
#include <System.SysUtils.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

int F2_TrailX1, F2_TrailY1, F2_Trail_i1; //Координаты для 1го Следа
int F2_TrailX2, F2_TrailY2, F2_Trail_i2;
int F2_TrailX3, F2_TrailY3, F2_Trail_i3;
int F2_TrailX4, F2_TrailY4, F2_Trail_i4;
int F2_TrailX5, F2_TrailY5, F2_Trail_i5;
int F2_TrailX6, F2_TrailY6, F2_Trail_i6;
int F2_TrailX7, F2_TrailY7, F2_Trail_i7;
int F2_TrailX8, F2_TrailY8, F2_Trail_i8;
int F2_TrailX9, F2_TrailY9, F2_Trail_i9;
int F2_TrailX10, F2_TrailY10, F2_Trail_i10;

int F2_BarrierX1, F2_BarrierY1, F2_Barrier_i1; //Координаты 1ой преграды
int F2_BarrierX2, F2_BarrierY2, F2_Barrier_i2;
int F2_BarrierX3, F2_BarrierY3, F2_Barrier_i3;
int F2_BarrierX4, F2_BarrierY4, F2_Barrier_i4;
int F2_BarrierX5, F2_BarrierY5, F2_Barrier_i5;
int F2_BarrierX6, F2_BarrierY6, F2_Barrier_i6;
int F2_BarrierX7, F2_BarrierY7, F2_Barrier_i7;
int F2_BarrierX8, F2_BarrierY8, F2_Barrier_i8;
int F2_BarrierX9, F2_BarrierY9, F2_Barrier_i9;
int F2_BarrierX10, F2_BarrierY10, F2_Barrier_i10;

int F2_PlanetX1, F2_PlanetY1, F2_Planet_i1; //Координаты 1ой планеты
int F2_PlanetX2, F2_PlanetY2, F2_Planet_i2;
int F2_PlanetX3, F2_PlanetY3, F2_Planet_i3;
int F2_PlanetX4, F2_PlanetY4, F2_Planet_i4;
int F2_PlanetX5, F2_PlanetY5, F2_Planet_i5;

int F2_PortalX1, F2_PortalY1, F2_Portal_i1, F2_Portal_j1; //Портал

int CD_SHIELD = 0;
int JUMP = 0, CD_JUMP = 0;
int RESIZING = 0; //Если 0 - то компоненты не были отмасштабированы, если 1 - все ок.
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;

void F2_BARRIER()
{
//Barrier1...
	//Масштабирование:
	Form2->Barrier1->Position->X = Form2->Width + 50;
	Form2->Barrier1->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	//Сохранение координат:
	F2_BarrierX1 = Form2->Barrier1->Position->X;
	F2_BarrierY1 = Form2->Barrier1->Position->Y;
	F2_Barrier_i1 = Form2->Barrier1->Position->X;

//Barrier2...
	//Масштабирование:
	Form2->Barrier2->Position->X = Form2->Width + 150;
	Form2->Barrier2->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2); //Random от верхнего Barrier до центра Form

	//Сохранение координат:
	F2_BarrierX2 = Form2->Barrier2->Position->X;
	F2_BarrierY2 = Form2->Barrier2->Position->Y;
	F2_Barrier_i2 = Form2->Barrier2->Position->X;

//Barrier3 (всегда с верху)...
	//Масштабирование:
	Form2->Barrier3->Position->X = Form2->Width + 150;
	Form2->Barrier3->Position->Y = 0;

	//Сохранение координат:
	F2_BarrierX3 = Form2->Barrier3->Position->X;
	F2_BarrierY3 = 0;
	F2_Barrier_i3 = Form2->Barrier3->Position->X;

//Barrier4 (всегда с низу)...
	//Масштабирование:
	Form2->Barrier4->Position->X = Form2->Width + 150;
	Form2->Barrier4->Position->Y = Form2->Height - Form2->Barrier4->Height;

	//Сохранение координат:
	F2_BarrierX4 = Form2->Barrier4->Position->X;
	F2_BarrierY4 = Form2->Barrier4->Position->Y;
	F2_Barrier_i4 = Form2->Barrier4->Position->X;

//Barrier5 (всегда с низу)...
	//Масштабирование:
	Form2->Barrier5->Position->X = Form2->Width + 150;
	Form2->Barrier5->Position->Y = Form2->Height / 2 + Random(Form2->Height / 2 - 70); //Random от центра Form до начала нижнего Barrier

	//Сохранение координат:
	F2_BarrierX5 = Form2->Barrier5->Position->X;
	F2_BarrierY5 = Form2->Barrier5->Position->Y;
	F2_Barrier_i5 = Form2->Barrier5->Position->X;

//Barrier6 (всегда с верху)...
	//Масштабирование:
	Form2->Barrier6->Position->X = Form2->Width + 50;
	Form2->Barrier6->Position->Y = 0;

	//Сохранение координат:
	F2_BarrierX6 = Form2->Barrier6->Position->X;
	F2_BarrierY6 = Form2->Barrier6->Position->Y;
	F2_Barrier_i6 = Form2->Barrier6->Position->X;

//Barrier7...
	//Масштабирование:
	Form2->Barrier7->Position->X = Form2->Width + 50;
	Form2->Barrier7->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	//Сохранение координат:
	F2_BarrierX7 = Form2->Barrier7->Position->X;
	F2_BarrierY7 = Form2->Barrier7->Position->Y;
	F2_Barrier_i7 = Form2->Barrier7->Position->X;

//Barrier8...
	//Масштабирование:
	Form2->Barrier8->Position->X = Form2->Width + 50;
	Form2->Barrier8->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	//Сохранение координат:
	F2_BarrierX8 = Form2->Barrier8->Position->X;
	F2_BarrierY8 = Form2->Barrier8->Position->Y;
	F2_Barrier_i8 = Form2->Barrier8->Position->X;

//Barrier9...
	//Масштабирование:
	Form2->Barrier9->Position->X = Form2->Width + 50;
	Form2->Barrier9->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	//Сохранение координат:
	F2_BarrierX9 = Form2->Barrier9->Position->X;
	F2_BarrierY9 = Form2->Barrier9->Position->Y;
	F2_Barrier_i9 = Form2->Barrier9->Position->X;

//Barrier10...
	//Масштабирование:
	Form2->Barrier10->Position->X = Form2->Width + 50;
	Form2->Barrier10->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	//Сохранение координат:
	F2_BarrierX10 = Form2->Barrier10->Position->X;
	F2_BarrierY10 = Form2->Barrier10->Position->Y;
	F2_Barrier_i10 = Form2->Barrier10->Position->X;
}

void F2_PLANET()
{
//Planet1...
	//Масштабирование:
	Form2->Planet1->Position->X = Form2->Width + 100;
	Form2->Planet1->Position->Y = 10 + Random(Form2->Height - Form2->Planet1->Height - 10);

	//Сохранение координат:
	F2_PlanetX1 = Form2->Planet1->Position->X;
	F2_PlanetY1 = Form2->Planet1->Position->Y;
	F2_Planet_i1 = Form2->Planet1->Position->X;

//Planet2...
	//Масштабирование:
	Form2->Planet2->Position->X = Form2->Width + 100;
	Form2->Planet2->Position->Y = 10 + Random(Form2->Height - Form2->Planet2->Height - 10);

	//Сохранение координат:
	F2_PlanetX2 = Form2->Planet2->Position->X;
	F2_PlanetY2 = Form2->Planet2->Position->Y;
	F2_Planet_i2 = Form2->Planet2->Position->X;

//Planet3...
	//Масштабирование:
	Form2->Planet3->Position->X = Form2->Width + 100;
	Form2->Planet3->Position->Y = 10 + Random(Form2->Height - Form2->Planet3->Height - 10);

	//Сохранение координат:
	F2_PlanetX3 = Form2->Planet3->Position->X;
	F2_PlanetY3 = Form2->Planet3->Position->Y;
	F2_Planet_i3 = Form2->Planet3->Position->X;

//Planet4...
	//Масштабирование:
	Form2->Planet4->Position->X = Form2->Width + 100;
	Form2->Planet4->Position->Y = 10 + Random(Form2->Height - Form2->Planet4->Height - 10);

	//Сохранение координат:
	F2_PlanetX4 = Form2->Planet4->Position->X;
	F2_PlanetY4 = Form2->Planet4->Position->Y;
	F2_Planet_i4 = Form2->Planet4->Position->X;

//Planet5...
	//Масштабирование:
	Form2->Planet5->Position->X = Form2->Width + 200;
	Form2->Planet5->Position->Y = Random(Form2->Height - Form2->Planet5->Height);

	//Сохранение координат:
	F2_PlanetX5 = Form2->Planet5->Position->X;
	F2_PlanetY5 = Form2->Planet5->Position->Y;
	F2_Planet_i5 = Form2->Planet5->Position->X;

//Portal...
	//Масштабирование:
	Form2->Portal->Position->X = Form2->Width + 400;
	Form2->Portal->Position->Y = Form2->Height / 2 - Form2->Portal->Height / 2;

	//Сохранение координат:
	F2_PortalX1 = Form2->Portal->Position->X;
	F2_PortalY1 = Form2->Portal->Position->Y;
	F2_Portal_i1 = Form2->Portal->Position->X;
	F2_Portal_j1 = Form2->Portal->Position->Y;

//Делаем планеты видимыми
	Form2->Planet1->Visible = true;
	Form2->Planet2->Visible = true;
	Form2->Planet3->Visible = true;
	Form2->Planet4->Visible = true;
	Form2->Planet5->Visible = true;
}

void F2_TRAIL()
{
//Trail1...
	//Масштабирование:
	Form2->Trail1->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail1->Position->Y = Form2->MainSpherePlayer->Position->Y;

	//Сохранение координат:
	F2_TrailX1 = Form2->Trail1->Position->X;
	F2_TrailY1 = Form2->Trail1->Position->Y;
	F2_Trail_i1 = Form2->Trail1->Position->X;

//Trail2...
	//Масштабирование:
	Form2->Trail2->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail2->Position->Y = Form2->MainSpherePlayer->Position->Y + 20;

	//Сохранение координат:
	F2_TrailX2 = Form2->Trail2->Position->X;
	F2_TrailY2 = Form2->Trail2->Position->Y;
	F2_Trail_i2 = Form2->Trail2->Position->X;

//Trail3...
	//Масштабирование:
	Form2->Trail3->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail3->Position->Y = Form2->MainSpherePlayer->Position->Y + 25;

	//Сохранение координат:
	F2_TrailX3 = Form2->Trail3->Position->X;
	F2_TrailY3 = Form2->Trail3->Position->Y;
	F2_Trail_i3 = Form2->Trail3->Position->X;

//Trail4...
	//Масштабирование:
	Form2->Trail4->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail4->Position->Y = Form2->MainSpherePlayer->Position->Y + 30;

	//Сохранение координат:
	F2_TrailX4 = Form2->Trail4->Position->X;
	F2_TrailY4 = Form2->Trail4->Position->Y;
	F2_Trail_i4 = Form2->Trail4->Position->X;

//Trail5...
	//Масштабирование:
	Form2->Trail5->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail5->Position->Y = Form2->MainSpherePlayer->Position->Y + 15;

	//Сохранение координат:
	F2_TrailX5 = Form2->Trail5->Position->X;
	F2_TrailY5 = Form2->Trail5->Position->Y;
	F2_Trail_i5 = Form2->Trail5->Position->X;

//Trail6...
	//Масштабирование:
	Form2->Trail6->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail6->Position->Y = Form2->MainSpherePlayer->Position->Y + 35;

	//Сохранение координат:
	F2_TrailX6 = Form2->Trail6->Position->X;
	F2_TrailY6 = Form2->Trail6->Position->Y;
	F2_Trail_i6 = Form2->Trail6->Position->X;

//Trail7...
	//Масштабирование:
	Form2->Trail7->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail7->Position->Y = Form2->MainSpherePlayer->Position->Y + 40;

	//Сохранение координат:
	F2_TrailX7 = Form2->Trail7->Position->X;
	F2_TrailY7 = Form2->Trail7->Position->Y;
	F2_Trail_i7 = Form2->Trail7->Position->X;

//Trail8...
	//Масштабирование:
	Form2->Trail8->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail8->Position->Y = Form2->MainSpherePlayer->Position->Y + 27;

	//Сохранение координат:
	F2_TrailX8 = Form2->Trail8->Position->X;
	F2_TrailY8 = Form2->Trail8->Position->Y;
	F2_Trail_i8 = Form2->Trail8->Position->X;

//Trail9...
	//Масштабирование:
	Form2->Trail9->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail9->Position->Y = Form2->MainSpherePlayer->Position->Y + 10;

	//Сохранение координат:
	F2_TrailX9 = Form2->Trail9->Position->X;
	F2_TrailY9 = Form2->Trail9->Position->Y;
	F2_Trail_i9 = Form2->Trail9->Position->X;

//Trail10...
	//Масштабирование:
	Form2->Trail10->Position->X = Form2->MainSpherePlayer->Position->X;
	Form2->Trail10->Position->Y = Form2->MainSpherePlayer->Position->Y + 38;

	//Сохранение координат:
	F2_TrailX10 = Form2->Trail10->Position->X;
	F2_TrailY10 = Form2->Trail10->Position->Y;
	F2_Trail_i10 = Form2->Trail10->Position->X;

//Shield...
	//Масштабирование:
	Form2->PlayerShield->Position->X = Form2->MainSpherePlayer->Position->X - 40;
	Form2->PlayerShield->Position->Y = Form2->MainSpherePlayer->Position->Y - Form2->PlayerShield->Height / 2 + 17; //Подгоняем
}

void EXPLORE()
{
	Form2->Trail1->Visible = true;
	Form2->Trail2->Visible = true;
	Form2->Trail3->Visible = true;
	Form2->Trail4->Visible = true;
	Form2->Trail5->Visible = true;
	Form2->Trail6->Visible = true;
	Form2->Trail7->Visible = true;
	Form2->Trail8->Visible = true;
	Form2->Trail9->Visible = true;
	Form2->Trail10->Visible = true;

	Form2->TimerTrail1Start->Enabled = false;
	Form2->TimerTrail2Start->Enabled = false;
	Form2->TimerTrail3Start->Enabled = false;
	Form2->TimerTrail4Start->Enabled = false;
	Form2->TimerTrail5Start->Enabled = false;
	Form2->TimerTrail6Start->Enabled = false;
	Form2->TimerTrail7Start->Enabled = false;
	Form2->TimerTrail8Start->Enabled = false;
	Form2->TimerTrail9Start->Enabled = false;
	Form2->TimerTrail10Start->Enabled = false;

	Form2->TimerTrail1End->Enabled = false;
	Form2->TimerTrail2End->Enabled = false;
	Form2->TimerTrail3End->Enabled = false;
	Form2->TimerTrail4End->Enabled = false;
	Form2->TimerTrail5End->Enabled = false;
	Form2->TimerTrail6End->Enabled = false;
	Form2->TimerTrail7End->Enabled = false;
	Form2->TimerTrail8End->Enabled = false;
	Form2->TimerTrail9End->Enabled = false;
	Form2->TimerTrail10End->Enabled = false;

	//Загоняем шарик в Сферу(игрока) что бы не было видно совсем, т.к. он большой
	Form2->Trail10->Position->X = Form2->MainSpherePlayer->Position->X + Form2->MainSpherePlayer->Width / 2;

	Form2->TimerExplorer1->Enabled = true;
	Form2->TimerExplorer2->Enabled = true;

	Form2->HEALTH->Text = StrToInt(Form2->HEALTH->Text) -1; //Вычитаем одну жизнь за столкновение

//Game Over
	if(StrToInt(Form2->HEALTH->Text) == 0)
	{
		Form2->TimerHealth->Enabled = true;
		Form2->TimerGameOver->Enabled = true;
	}

//Вычитаем одну жизнь за столкновение
	if(StrToInt(Form2->HEALTH->Text) == 1)
	{
		Form2->TimerGame->Enabled = true;
		Form2->TimerHealth->Enabled = true;
	}

//Вычитаем одну жизнь за столкновение
	if(StrToInt(Form2->HEALTH->Text) == 2)
	{
		Form2->TimerGame->Enabled = true;
		Form2->TimerHealth->Enabled = true;
	}
}

void IN_PORTAL()
{
	Form2->Trail1->Visible = true;
	Form2->Trail2->Visible = true;
	Form2->Trail3->Visible = true;
	Form2->Trail4->Visible = true;
	Form2->Trail5->Visible = true;
	Form2->Trail6->Visible = true;
	Form2->Trail7->Visible = true;
	Form2->Trail8->Visible = true;
	Form2->Trail9->Visible = true;
	Form2->Trail10->Visible = true;

	Form2->TimerTrail1Start->Enabled = false;
	Form2->TimerTrail2Start->Enabled = false;
	Form2->TimerTrail3Start->Enabled = false;
	Form2->TimerTrail4Start->Enabled = false;
	Form2->TimerTrail5Start->Enabled = false;
	Form2->TimerTrail6Start->Enabled = false;
	Form2->TimerTrail7Start->Enabled = false;
	Form2->TimerTrail8Start->Enabled = false;
	Form2->TimerTrail9Start->Enabled = false;
	Form2->TimerTrail10Start->Enabled = false;

	Form2->TimerTrail1End->Enabled = false;
	Form2->TimerTrail2End->Enabled = false;
	Form2->TimerTrail3End->Enabled = false;
	Form2->TimerTrail4End->Enabled = false;
	Form2->TimerTrail5End->Enabled = false;
	Form2->TimerTrail6End->Enabled = false;
	Form2->TimerTrail7End->Enabled = false;
	Form2->TimerTrail8End->Enabled = false;
	Form2->TimerTrail9End->Enabled = false;
	Form2->TimerTrail10End->Enabled = false;

	//Загоняем шарик в Сферу(игрока) что бы не было видно совсем, т.к. он большой
	Form2->Trail10->Position->X = Form2->MainSpherePlayer->Position->X + Form2->MainSpherePlayer->Width / 2;

	Form2->TimerInPortal1->Enabled = true;
	Form2->TimerInPortal2->Enabled = true;
}

void GAME()
{
//Включаем движение игрока..................
	Form2->STATUS->Text = "RUN"; //Полет нормальный

	Form2->MainSpherePlayer->Visible = true;

	Form2->TimerExplorer1->Enabled = false;
	Form2->TimerExplorer2->Enabled = false;
	Form2->TimerExplorer3->Enabled = false;

	Form2->MainSpherePlayer->Position->X = 100;
	Form2->MainSpherePlayer->Position->Y = Form2->Height / 2 - Form2->MainSpherePlayer->Height / 2;

//	F2_TRAIL();

	Form2->Trail1->Visible = true;
	Form2->Trail2->Visible = true;
	Form2->Trail3->Visible = true;
	Form2->Trail4->Visible = true;
	Form2->Trail5->Visible = true;
	Form2->Trail6->Visible = true;
	Form2->Trail7->Visible = true;
	Form2->Trail8->Visible = true;
	Form2->Trail9->Visible = true;
	Form2->Trail10->Visible = true;

	Form2->TimerTrail1Start->Enabled = true;
	Form2->TimerTrail2Start->Enabled = true;
	Form2->TimerTrail3Start->Enabled = true;
	Form2->TimerTrail4Start->Enabled = true;
	Form2->TimerTrail5Start->Enabled = true;
	Form2->TimerTrail6Start->Enabled = true;
	Form2->TimerTrail7Start->Enabled = true;
	Form2->TimerTrail8Start->Enabled = true;
	Form2->TimerTrail9Start->Enabled = true;
	Form2->TimerTrail10Start->Enabled = true;

	Form2->MainSpherePlayer->Width = 75;
	Form2->MainSpherePlayer->Height = 50;
	Form2->MainSpherePlayer->XRadius = 0;
	Form2->MainSpherePlayer->YRadius = 0;
}

void F2_RESIZE_COMPONENTS()
{
//Кнопки...
//Left side
	Form2->BtnPlayerUp->Position->X = 4;
	Form2->BtnPlayerUp->Position->Y = Form2->Height - Form2->BtnPlayerDown->Height - 4;

	Form2->BtnPlayerJump->Position->X = 4;
	Form2->BtnPlayerJump->Position->Y = Form2->Height - Form2->BtnPlayerUp->Height - 4 - Form2->BtnPlayerJump->Height;

	Form2->CdPlayerJump->Position->X = Form2->BtnPlayerJump->Position->X + Form2->BtnPlayerJump->Width / 2 - Form2->CdPlayerShield->Width / 2 + 8; //+8 - подгон
	Form2->CdPlayerJump->Position->Y = Form2->BtnPlayerJump->Position->Y + Form2->BtnPlayerJump->Height / 2 - Form2->CdPlayerJump->Height / 2 - 2; //-2 - подгон

//Right side
	Form2->BtnPlayerDown->Position->X = Form2->Width - Form2->BtnPlayerDown->Width - 4;
	Form2->BtnPlayerDown->Position->Y = Form2->Height - Form2->BtnPlayerDown->Height - 4;

	Form2->BtnPlayerShield->Position->X = Form2->Width - Form2->BtnPlayerDown->Width - 4;
	Form2->BtnPlayerShield->Position->Y = Form2->Height - Form2->BtnPlayerDown->Height - 4 - Form2->BtnPlayerShield->Height;

	Form2->CdPlayerShield->Position->X = Form2->BtnPlayerShield->Position->X + Form2->BtnPlayerShield->Width / 2 - Form2->CdPlayerShield->Width / 2 + 9; //+4 - подгон
	Form2->CdPlayerShield->Position->Y = Form2->BtnPlayerShield->Position->Y + Form2->BtnPlayerShield->Height / 2 - Form2->CdPlayerShield->Height / 2 - 2; //-2 - подгон

//Center
//HP...
	Form2->Health2->Position->X = Form2->Width / 2 - Form2->Health2->Width / 2;
	Form2->Health2->Position->Y = 4;

	Form2->Health1->Position->X = Form2->Health2->Position->X - Form2->Health2->Width + 1;
	Form2->Health1->Position->Y = 4;

	Form2->Health3->Position->X = Form2->Health2->Position->X + Form2->Health2->Width - 1;
	Form2->Health3->Position->Y = 4;

//Label2,..7...
	Form2->Label1->Position->X = Form2->Width / 2 - Form2->Label1->Width / 2;
	Form2->Label1->Position->Y = Form2->Height / 2 - Form2->Label1->Height / 2;

	Form2->Label2->Position->X = Form2->Width / 2 - Form2->Label2->Width / 2;
	Form2->Label2->Position->Y = Form2->Height / 2 - Form2->Label2->Height / 2;

	Form2->Label3->Position->X = Form2->Width / 2 - Form2->Label3->Width / 2;
	Form2->Label3->Position->Y = Form2->Height / 2 - Form2->Label3->Height / 2;

	Form2->Label4->Position->X = Form2->Width / 2 - Form2->Label4->Width / 2;
	Form2->Label4->Position->Y = Form2->Height / 2 - Form2->Label4->Height / 2;

	Form2->Label5->Position->X = Form2->Width / 2 - Form2->Label5->Width / 2;
	Form2->Label5->Position->Y = Form2->Height / 2 - Form2->Label5->Height / 2;

	Form2->Label6->Position->X = Form2->Width / 2 - Form2->Label6->Width / 2;
	Form2->Label6->Position->Y = Form2->Height / 2 - Form2->Label6->Height / 2;

	Form2->Label7->Position->X = Form2->Width / 2 - Form2->Label7->Width / 2;
	Form2->Label7->Position->Y = Form2->Height / 2 - Form2->Label7->Height / 2;

	Form2->Label8->Position->X = Form2->Width / 2 - Form2->Label8->Width / 2;
	Form2->Label8->Position->Y = Form2->Height / 2 - Form2->Label8->Height / 2;
}

void HIDE_COMPONENTS()
{
	Form2->Trail1->Visible = false;
	Form2->Trail2->Visible = false;
	Form2->Trail3->Visible = false;
	Form2->Trail4->Visible = false;
	Form2->Trail5->Visible = false;
	Form2->Trail6->Visible = false;
	Form2->Trail7->Visible = false;
	Form2->Trail8->Visible = false;
	Form2->Trail9->Visible = false;
	Form2->Trail10->Visible = false;

	Form2->Barrier1->Visible = false;
	Form2->Barrier2->Visible = false;
	Form2->Barrier3->Visible = false;
	Form2->Barrier4->Visible = false;
	Form2->Barrier5->Visible = false;
	Form2->Barrier6->Visible = false;
	Form2->Barrier7->Visible = false;
	Form2->Barrier8->Visible = false;
	Form2->Barrier9->Visible = false;
	Form2->Barrier10->Visible = false;

	Form2->STATUS->Visible = false;
	Form2->HEALTH->Visible = false;

	Form2->Planet1->Visible = false;
	Form2->Planet2->Visible = false;
	Form2->Planet3->Visible = false;
	Form2->Planet4->Visible = false;
	Form2->Planet5->Visible = false;

	Form2->Portal->Visible = false;

	Form2->Button2->Visible = false; //Для вызова ф-ции сжатия сферы игрока

	Form2->MainSpherePlayer->Visible = false;
	Form2->PlayerShield->Visible = false;
	Form2->CdPlayerShield->Visible = false;
	Form2->CdPlayerJump->Visible = false;

	Form2->Label1->Visible = false;
	Form2->Label2->Visible = false;
	Form2->Label3->Visible = false;
	Form2->Label4->Visible = false;
	Form2->Label5->Visible = false;
	Form2->Label6->Visible = false;
	Form2->Label7->Visible = false;
	Form2->Label8->Visible = false;
}

void RESET()
{
	Form2->TimerTrail1Start->Enabled = false;
	Form2->TimerTrail2Start->Enabled = false;
	Form2->TimerTrail3Start->Enabled = false;
	Form2->TimerTrail4Start->Enabled = false;
	Form2->TimerTrail5Start->Enabled = false;
	Form2->TimerTrail6Start->Enabled = false;
	Form2->TimerTrail7Start->Enabled = false;
	Form2->TimerTrail8Start->Enabled = false;
	Form2->TimerTrail9Start->Enabled = false;
	Form2->TimerTrail10Start->Enabled = false;

	Form2->TimerTrail1End->Enabled = false;
	Form2->TimerTrail2End->Enabled = false;
	Form2->TimerTrail3End->Enabled = false;
	Form2->TimerTrail4End->Enabled = false;
	Form2->TimerTrail5End->Enabled = false;
	Form2->TimerTrail6End->Enabled = false;
	Form2->TimerTrail7End->Enabled = false;
	Form2->TimerTrail8End->Enabled = false;
	Form2->TimerTrail9End->Enabled = false;
	Form2->TimerTrail10End->Enabled = false;

	Form2->TimerExplorer1->Enabled = false;
	Form2->TimerExplorer2->Enabled = false;
	Form2->TimerExplorer3->Enabled = false;

	Form2->TimerFly->Enabled = false;
	Form2->TimerGameOver->Enabled = false;

	Form2->TimerGame->Enabled = false;
	Form2->TimerGame1->Enabled = false;
	Form2->TimerGame2->Enabled = false;
	Form2->TimerGame3->Enabled = false;
	Form2->TimerGame4->Enabled = false;
	Form2->TimerGame5->Enabled = false;
	Form2->TimerGame6->Enabled = false;
	Form2->TimerGame7->Enabled = false;
	Form2->TimerWin->Enabled = false;

	Form2->TimerDifficultStart->Enabled = false;
	Form2->TimerDifficult1->Enabled = false;
	Form2->TimerDifficult2->Enabled = false;
	Form2->TimerDifficult3->Enabled = false;
	Form2->TimerDifficult4->Enabled = false;
	Form2->TimerDifficult5->Enabled = false;
	Form2->TimerDifficult6->Enabled = false;

	Form2->TimerBarrier1Start->Enabled = false;
	Form2->TimerBarrier1End->Enabled = false;
	Form2->TimerBarrier2Start->Enabled = false;
	Form2->TimerBarrier2End->Enabled = false;
	Form2->TimerBarrier3Start->Enabled = false;
	Form2->TimerBarrier3End->Enabled = false;
	Form2->TimerBarrier4Start->Enabled = false;
	Form2->TimerBarrier4End->Enabled = false;
	Form2->TimerBarrier5Start->Enabled = false;
	Form2->TimerBarrier5End->Enabled = false;
	Form2->TimerBarrier6Start->Enabled = false;
	Form2->TimerBarrier6End->Enabled = false;
	Form2->TimerBarrier7Start->Enabled = false;
	Form2->TimerBarrier7End->Enabled = false;
	Form2->TimerBarrier8Start->Enabled = false;
	Form2->TimerBarrier8End->Enabled = false;
	Form2->TimerBarrier9Start->Enabled = false;
	Form2->TimerBarrier9End->Enabled = false;
	Form2->TimerBarrier10Start->Enabled = false;
	Form2->TimerBarrier10End->Enabled = false;

	Form2->TimerPlanet1Start->Enabled = false;
	Form2->TimerPlanet1End->Enabled = false;
	Form2->TimerPlanet2Start->Enabled = false;
	Form2->TimerPlanet2End->Enabled = false;
	Form2->TimerPlanet3Start->Enabled = false;
	Form2->TimerPlanet3End->Enabled = false;
	Form2->TimerPlanet4Start->Enabled = false;
	Form2->TimerPlanet4End->Enabled = false;
	Form2->TimerPlanet5Start->Enabled = false;
	Form2->TimerPlanet5End->Enabled = false;

	Form2->TimerPortal1Up->Enabled = false;
	Form2->TimerPortal1Down->Enabled = false;
	Form2->TimerSpereCenter->Enabled = false;
	Form2->TimerPortal1Start->Enabled = false;
	Form2->TimerSpereFly->Enabled = false;
	Form2->TimerPortal1End->Enabled = false;
	Form2->TimerPortalHide->Enabled = false;

	Form2->TimerPlayerShield1Up->Enabled = false;
	Form2->TimerPlayerShield1Down->Enabled = false;

	CD_SHIELD = 0; //Время перезарядки защитного щита

	Form2->CdPlayerShield->Visible = false;
	Form2->BtnPlayerShield->Enabled = false;
	Form2->TimerPlayerShield1Cd->Enabled = false;

	Form2->MainSpherePlayer->Width = 75;
	Form2->MainSpherePlayer->Height = 50;
	Form2->MainSpherePlayer->XRadius = 0;
	Form2->MainSpherePlayer->YRadius = 0;

	JUMP = 0;
	CD_JUMP = 0;
	Form2->CdPlayerJump->Visible = false;
	Form2->BtnPlayerJump->Enabled = false;
	Form2->TimerPlayerJumpCd->Enabled = false;
	Form2->TimerPlayerJumpEnd->Enabled = false;
	Form2->TimerPlayerJumpDown->Enabled = false;
	Form2->TimerPlayerJumpStart->Enabled = false;

	Form2->MediaPlayer1->Stop();
	Form2->MediaPlayer2->Stop();
	Form2->TimerMusic->Enabled = false;
	Form2->TimerExplosion->Enabled = false;

	RESIZING = 0;

	Form2->TimerStartAnimationBtnUp->Enabled = false;
	Form2->TimerStartAnimationBtnJump->Enabled = false;
	Form2->TimerStartAnimationBtnShield->Enabled = false;
	Form2->TimerStartAnimationBtnDown->Enabled = false;
	Form2->TimerStartAnimationHP->Enabled = false;
	Form2->TimerForResizing->Enabled = false;
	Form2->TimerStartPosition->Enabled = false;
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerExplorer1Timer(TObject *Sender)
{
//Всасываем шлейф для дальнейшего взрыва
	if(Trail1->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail1->Position->X++; }
	if(Trail2->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail2->Position->X++; }
	if(Trail3->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail3->Position->X++; }
	if(Trail4->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail4->Position->X++; }
	if(Trail5->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail5->Position->X++; }
	if(Trail6->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail6->Position->X++; }
	if(Trail7->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail7->Position->X++; }
	if(Trail8->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail8->Position->X++; }
	if(Trail9->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail9->Position->X++; }
	if(Trail10->Position->X < MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 - 10) { Trail10->Position->X++; }

	if(Trail1->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail1->Position->Y++; } else { Trail1->Position->Y--; }
	if(Trail2->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail2->Position->Y++; } else { Trail2->Position->Y--; }
	if(Trail3->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail3->Position->Y++; } else { Trail3->Position->Y--; }
	if(Trail4->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail4->Position->Y++; } else { Trail4->Position->Y--; }
	if(Trail5->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail5->Position->Y++; } else { Trail5->Position->Y--; }
	if(Trail6->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail6->Position->Y++; } else { Trail6->Position->Y--; }
	if(Trail7->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail7->Position->Y++; } else { Trail7->Position->Y--; }
	if(Trail8->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail8->Position->Y++; } else { Trail8->Position->Y--; }
	if(Trail9->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail9->Position->Y++; } else { Trail9->Position->Y--; }
	if(Trail10->Position->Y < MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2) { Trail10->Position->Y++; } else { Trail10->Position->Y--; }

//Выключаем стягивание для взрыва
	if(Trail1->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail2->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail3->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail4->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail5->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail6->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail7->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail8->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail9->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5 &&
	   Trail10->Position->X >= MainSpherePlayer->Position->X + MainSpherePlayer->Width / 2 + 5)
	{
		TimerExplorer1->Enabled = false;

		TimerTrail1Start->Enabled = false;
		TimerTrail2Start->Enabled = false;
		TimerTrail3Start->Enabled = false;
		TimerTrail4Start->Enabled = false;
		TimerTrail5Start->Enabled = false;
		TimerTrail6Start->Enabled = false;
		TimerTrail7Start->Enabled = false;
		TimerTrail8Start->Enabled = false;
		TimerTrail9Start->Enabled = false;
		TimerTrail10Start->Enabled = false;

		TimerTrail1End->Enabled = false;
		TimerTrail2End->Enabled = false;
		TimerTrail3End->Enabled = false;
		TimerTrail4End->Enabled = false;
		TimerTrail5End->Enabled = false;
		TimerTrail6End->Enabled = false;
		TimerTrail7End->Enabled = false;
		TimerTrail8End->Enabled = false;
		TimerTrail9End->Enabled = false;
		TimerTrail10End->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerExplorer2Timer(TObject *Sender)
{
//Раздуваем MainSpherePlayer
	if(MainSpherePlayer->Height < 85 && MainSpherePlayer->Width < 100)
	{
		MainSpherePlayer->Height++;
		MainSpherePlayer->Width++; MainSpherePlayer->Width++;

		MainSpherePlayer->Position->X--; MainSpherePlayer->Position->X--;
		MainSpherePlayer->Position->Y--;
	}

	if(MainSpherePlayer->Height >= 85 || MainSpherePlayer->Width >= 100)
	{
		STATUS->Text = "EXPLORE"; //Взрыв, столкновение

		TimerExplorer2->Enabled = false;
		TimerExplorer3->Enabled = true;

		Trail1->Visible = false;
		Trail2->Visible = false;
		Trail3->Visible = false;
		Trail4->Visible = false;
		Trail5->Visible = false;
		Trail6->Visible = false;
		Trail7->Visible = false;
		Trail8->Visible = false;
		Trail9->Visible = false;
		Trail10->Visible = false;

		//ВКЛ звук взрыва...
		MediaPlayer2->FileName = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "Expl.mp3";
		MediaPlayer2->Play(); TimerExplosion->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerExplorer3Timer(TObject *Sender)
{
	if(MainSpherePlayer->Height < 100 && MainSpherePlayer->Width < 150)
	{
		MainSpherePlayer->Position->X--; MainSpherePlayer->Position->X--;
		MainSpherePlayer->Position->Y--; MainSpherePlayer->Position->Y--;

		MainSpherePlayer->Height++; MainSpherePlayer->Height++; MainSpherePlayer->Height++; MainSpherePlayer->Height++;
		MainSpherePlayer->Width++; MainSpherePlayer->Width++; MainSpherePlayer->Width++; MainSpherePlayer->Width++;
		MainSpherePlayer->XRadius++; MainSpherePlayer->XRadius++; MainSpherePlayer->XRadius++; MainSpherePlayer->XRadius++;
		MainSpherePlayer->YRadius++; MainSpherePlayer->YRadius++; MainSpherePlayer->YRadius++; MainSpherePlayer->YRadius++;
	}

	if(MainSpherePlayer->Height > 100 || MainSpherePlayer->Width > 150)
	{
		TimerExplorer3->Enabled = false;
		MainSpherePlayer->Visible = false;

		Trail1->Visible = true;
		Trail2->Visible = true;
		Trail3->Visible = true;
		Trail4->Visible = true;
		Trail5->Visible = true;
		Trail6->Visible = true;
		Trail7->Visible = true;
		Trail8->Visible = true;
		Trail9->Visible = true;
		Trail10->Visible = true;

		TimerTrail1Start->Enabled = true;
		TimerTrail2Start->Enabled = true;
		TimerTrail3Start->Enabled = true;
		TimerTrail4Start->Enabled = true;
		TimerTrail5Start->Enabled = true;
		TimerTrail6Start->Enabled = true;
		TimerTrail7Start->Enabled = true;
		TimerTrail8Start->Enabled = true;
		TimerTrail9Start->Enabled = true;
		TimerTrail10Start->Enabled = true;

//		TimerFly->Enabled = true; Его мы будем включать после пропадания щита неуязвимости.
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerFlyTimer(TObject *Sender)
{
// /*
	if(MainSpherePlayer->Position->X <= Barrier1->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +60 >= Barrier1->Position->X + Barrier1->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier1->Position->Y + Barrier1->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier1->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier2->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +85 >= Barrier2->Position->X + Barrier2->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier2->Position->Y + Barrier2->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier2->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier3->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +40 >= Barrier3->Position->X + Barrier3->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier3->Position->Y + Barrier3->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier3->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier4->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +40 >= Barrier4->Position->X + Barrier4->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier4->Position->Y + Barrier4->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier4->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier5->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +50 >= Barrier5->Position->X + Barrier5->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier5->Position->Y + Barrier5->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier5->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier6->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +60 >= Barrier6->Position->X + Barrier6->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier6->Position->Y + Barrier6->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier6->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier7->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +85 >= Barrier7->Position->X + Barrier7->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier7->Position->Y + Barrier7->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier7->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier8->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +85 >= Barrier8->Position->X + Barrier8->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier8->Position->Y + Barrier8->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier8->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier9->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +50 >= Barrier9->Position->X + Barrier9->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier9->Position->Y + Barrier9->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier9->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}

	if(MainSpherePlayer->Position->X <= Barrier10->Position->X && //Столкновение лоб в лоб
		MainSpherePlayer->Position->X + MainSpherePlayer->Width +45 >= Barrier10->Position->X + Barrier10->Width && //Столкновение задом с концом преграды
		  MainSpherePlayer->Position->Y <= Barrier10->Position->Y + Barrier10->Height && //Столкновение с низу
		   MainSpherePlayer->Position->Y + MainSpherePlayer->Height >= Barrier10->Position->Y) //Столкновение с верху
		{
			TimerFly->Enabled = false;
			EXPLORE();
		}
// */
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier1StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i1 > - 50)
		{   //x8
			F2_Barrier_i1--; F2_Barrier_i1--; F2_Barrier_i1--; F2_Barrier_i1--;
			F2_Barrier_i1--; F2_Barrier_i1--; F2_Barrier_i1--; F2_Barrier_i1--;

			Barrier1->Position->X = F2_Barrier_i1;

			if(F2_Barrier_i1 <= - 50)
			{
				Barrier1->Visible = false;
				TimerBarrier1Start->Enabled = false;
				TimerBarrier1End->Interval = Random(3000);
				TimerBarrier1End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier1EndTimer(TObject *Sender)
{
	Barrier1->Visible = true;

	Barrier1->Position->X = F2_BarrierX1;
	Barrier1->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	F2_Barrier_i1 = F2_BarrierX1;

	TimerBarrier1End->Enabled = false;
	TimerBarrier1Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier2StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i2 > - 50)
		{   //x7
			F2_Barrier_i2--; F2_Barrier_i2--; F2_Barrier_i2--; F2_Barrier_i2--; F2_Barrier_i2--;
			F2_Barrier_i2--; F2_Barrier_i2--;

			Barrier2->Position->X = F2_Barrier_i2;

			if(F2_Barrier_i2 <= - 50)
			{
				Barrier2->Visible = false;
				TimerBarrier2Start->Enabled = false;
				TimerBarrier2End->Interval = Random(2000);
				TimerBarrier2End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier2EndTimer(TObject *Sender)
{
	Barrier2->Visible = true;

	Barrier2->Position->X = F2_BarrierX2;
	Barrier2->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2); //Random от верхнего Barrier до центра Form

	F2_Barrier_i2 = F2_BarrierX2;

	TimerBarrier2End->Enabled = false;
	TimerBarrier2Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
//Скрываем компоненты
	HIDE_COMPONENTS();

//Масштабирование планет и сохранение их координат
	F2_PLANET();

	F2_TRAIL();
	F2_BARRIER();

	MainSpherePlayer->Position->X = 100;
	MainSpherePlayer->Position->Y = Form2->Height / 2 - MainSpherePlayer->Height / 2;

//Скрываем разово компоненты для их плавного появления....
//Left side
	Form2->BtnPlayerUp->Visible = false;
	Form2->BtnPlayerJump->Visible = false;

//Right side
	Form2->BtnPlayerDown->Visible = false;
	Form2->BtnPlayerShield->Visible = false;

//Center
//HP...
	Form2->Health1->Visible = false;
	Form2->Health2->Visible = false;
	Form2->Health3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerSphereUpBtnTimer(TObject *Sender)
{
	if(MainSpherePlayer->Position->Y > 5)
	{
        F2_TRAIL();
		MainSpherePlayer->Position->Y = MainSpherePlayer->Position->Y - 10;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerSphereDownBtnTimer(TObject *Sender)
{
	if(MainSpherePlayer->Position->Y < Form2->Height - MainSpherePlayer->Height - 5)
	{
		F2_TRAIL();
		MainSpherePlayer->Position->Y = MainSpherePlayer->Position->Y + 10;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnPlayerUpMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true)
	{
		F2_TRAIL();
		TimerSphereUpBtn->Enabled = true;
		TimerSphereDownBtn->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnPlayerUpMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true)
	{
		F2_TRAIL();
		TimerSphereUpBtn->Enabled = false;
		TimerSphereDownBtn->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnPlayerDownMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true)
	{
		F2_TRAIL();
		TimerSphereDownBtn->Enabled = true;
		TimerSphereUpBtn->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnPlayerDownMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true)
	{
		F2_TRAIL();
		TimerSphereDownBtn->Enabled = false;
		TimerSphereUpBtn->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail1StartTimer(TObject *Sender)
{
	if(Form2->STATUS->Text == "RUN")
	{
		if(F2_Trail_i1 > F2_Trail_i1 - 60)
		{
			F2_Trail_i1--; F2_Trail_i1--; F2_Trail_i1--;

			Trail1->Position->X = F2_Trail_i1;

			if(F2_Trail_i1 <= MainSpherePlayer->Position->X - 60)
			{
				Trail1->Visible = false;
				TimerTrail1Start->Enabled = false;
				TimerTrail1End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail1->Position->X > -25)
		{
			Trail1->Position->X--; Trail1->Position->X--; Trail1->Position->X--; Trail1->Position->X--;

			if(Trail1->Position->X <= -25)
			{
				Trail1->Visible = false;
				TimerTrail1Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail2StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i2 > F2_Trail_i2 - 70)
		{
			F2_Trail_i2--; F2_Trail_i2--; F2_Trail_i2--;

			Trail2->Position->X = F2_Trail_i2;

			if(F2_Trail_i2 <= MainSpherePlayer->Position->X - 70)
			{
				Trail2->Visible = false;
				TimerTrail2Start->Enabled = false;
				TimerTrail2End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail2->Position->X < Form2->Width + 25)
		{
			Trail2->Position->X++; Trail2->Position->X++; Trail2->Position->X++; Trail2->Position->X++;

			if(Trail2->Position->X >= Form2->Width + 25)
			{
				Trail2->Visible = false;
				TimerTrail2Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail3StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i3 > F2_Trail_i3 - 50)
		{
			F2_Trail_i3--; F2_Trail_i3--;

			Trail3->Position->X = F2_Trail_i3;

			if(F2_Trail_i3 <= MainSpherePlayer->Position->X - 50)
			{
				Trail3->Visible = false;
				TimerTrail3Start->Enabled = false;
				TimerTrail3End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail3->Position->Y > -25)
		{
			Trail3->Position->Y--; Trail3->Position->Y--; Trail3->Position->Y--; Trail3->Position->Y--;

			if(Trail3->Position->X <= - 25)
			{
				Trail3->Visible = false;
				TimerTrail3Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail4StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i4 > F2_Trail_i4 - 80)
		{
			F2_Trail_i4--; F2_Trail_i4--; F2_Trail_i4--;

			Trail4->Position->X = F2_Trail_i4;

			if(F2_Trail_i4 <= MainSpherePlayer->Position->X - 80)
			{
				Trail4->Visible = false;
				TimerTrail4Start->Enabled = false;
				TimerTrail4End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail4->Position->Y < Form2->Height + 25)
		{
			Trail4->Position->Y++; Trail4->Position->Y++; Trail4->Position->Y++; Trail4->Position->Y++;

			if(Trail4->Position->X >= Form2->Height + 25)
			{
				Trail4->Visible = false;
				TimerTrail4Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail5StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i5 > F2_Trail_i4 - 40)
		{
			F2_Trail_i5--; F2_Trail_i5--; F2_Trail_i5--;

			Trail5->Position->X = F2_Trail_i5;

			if(F2_Trail_i5 <= MainSpherePlayer->Position->X - 40)
			{
				Trail5->Visible = false;
				TimerTrail5Start->Enabled = false;
				TimerTrail5End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail5->Position->X < Form2->Width + 25)
		{
			Trail5->Position->X++; Trail5->Position->X++;

			if(Trail5->Position->X >= Form2->Width + 25)
			{
				Trail5->Visible = false;
				TimerTrail5Start->Enabled = false;
			}
		}

		if(Trail5->Position->Y < Form2->Height + 25)
		{
			Trail5->Position->Y++; Trail5->Position->Y++; Trail5->Position->Y++;

			if(Trail5->Position->Y >= Form2->Height + 25)
			{
				Trail5->Visible = false;
				TimerTrail5Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail6StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i6 > F2_Trail_i6 - 90)
		{
			F2_Trail_i6--; F2_Trail_i6--;

			Trail6->Position->X = F2_Trail_i6;

			if(F2_Trail_i6 <= MainSpherePlayer->Position->X - 90)
			{
				Trail6->Visible = false;
				TimerTrail6Start->Enabled = false;
				TimerTrail6End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail6->Position->X > - 25)
		{
			Trail6->Position->X--; Trail6->Position->X--;

			if(Trail6->Position->X <= - 25)
			{
				Trail6->Visible = false;
				TimerTrail6Start->Enabled = false;
			}
		}

		if(Trail6->Position->Y > - 25)
		{
			Trail6->Position->Y--; Trail6->Position->Y--; Trail6->Position->Y--;

			if(Trail6->Position->Y <= -25)
			{
				Trail6->Visible = false;
				TimerTrail6Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail7StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i7 > F2_Trail_i7 - 75)
		{
			F2_Trail_i7--; F2_Trail_i7--; F2_Trail_i7--;

			Trail7->Position->X = F2_Trail_i7;

			if(F2_Trail_i7 <= MainSpherePlayer->Position->X - 75)
			{
				Trail7->Visible = false;
				TimerTrail7Start->Enabled = false;
				TimerTrail7End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail7->Position->X > - 25)
		{
			Trail7->Position->X--; Trail7->Position->X--;

			if(Trail7->Position->X <= - 25)
			{
				Trail7->Visible = false;
				TimerTrail7Start->Enabled = false;
			}
		}

		if(Trail7->Position->Y < Form2->Height + 25)
		{
			Trail7->Position->Y++; Trail7->Position->Y++; Trail7->Position->Y++;

			if(Trail7->Position->Y >= Form2->Height + 25)
			{
				Trail7->Visible = false;
				TimerTrail7Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail8StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i8 > F2_Trail_i8 - 55)
		{
			F2_Trail_i8--; F2_Trail_i8--;

			Trail8->Position->X = F2_Trail_i8;

			if(F2_Trail_i8 <= MainSpherePlayer->Position->X - 55)
			{
				Trail8->Visible = false;
				TimerTrail8Start->Enabled = false;
				TimerTrail8End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail8->Position->X < Form2->Width + 25)
		{
			Trail8->Position->X++; Trail8->Position->X++;

			if(Trail8->Position->X >= Form2->Width + 25)
			{
				Trail8->Visible = false;
				TimerTrail8Start->Enabled = false;
			}
		}

		if(Trail8->Position->Y > - 25)
		{
			Trail8->Position->Y--; Trail8->Position->Y--; Trail8->Position->Y--;

			if(Trail8->Position->Y <= - 25)
			{
				Trail8->Visible = false;
				TimerTrail8Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail9StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i9 > F2_Trail_i9 - 100)
		{
			F2_Trail_i9--; F2_Trail_i9--; F2_Trail_i9--;

			Trail9->Position->X = F2_Trail_i9;

			if(F2_Trail_i9 <= MainSpherePlayer->Position->X - 100)
			{
				Trail9->Visible = false;
				TimerTrail9Start->Enabled = false;
				TimerTrail9End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail9->Position->X < Form2->Width + 25)
		{
			Trail9->Position->X++; Trail9->Position->X++; Trail9->Position->X++; Trail9->Position->X++;

			if(Trail9->Position->X >= Form2->Width + 25)
			{
				Trail9->Visible = false;
				TimerTrail9Start->Enabled = false;
			}
		}

		if(Trail9->Position->Y < Form2->Height + 25)
		{
			Trail9->Position->Y++; Trail9->Position->Y++;

			if(Trail9->Position->Y >= Form2->Height + 25)
			{
				Trail9->Visible = false;
				TimerTrail9Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail10StartTimer(TObject *Sender)
{
	if(STATUS->Text == "RUN")
	{
		if(F2_Trail_i10 > F2_Trail_i10 - 80)
		{
			F2_Trail_i10--; F2_Trail_i10--;

			Trail10->Position->X = F2_Trail_i10;

			if(F2_Trail_i10 <= MainSpherePlayer->Position->X - 80)
			{
				Trail10->Visible = false;
				TimerTrail10Start->Enabled = false;
				TimerTrail10End->Enabled = true;
			}
		}
	}

	if(Form2->STATUS->Text == "EXPLORE")
	{
		if(Trail10->Position->X < Form2->Width + 25)
		{
			Trail10->Position->X++; Trail10->Position->X++; Trail10->Position->X++; Trail10->Position->X++;

			if(Trail10->Position->X >= Form2->Width + 25)
			{
				Trail10->Visible = false;
				TimerTrail10Start->Enabled = false;
			}
		}

		if(Trail10->Position->Y > - 25)
		{
			Trail10->Position->Y--; Trail10->Position->Y--;

			if(Trail10->Position->Y <= - 25)
			{
				Trail10->Visible = false;
				TimerTrail10Start->Enabled = false;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerTrail1EndTimer(TObject *Sender)
{
	Trail1->Visible = true;

	Trail1->Position->X = F2_TrailX1;
	Trail1->Position->Y = F2_TrailY1;

	F2_Trail_i1 = F2_TrailX1;

	TimerTrail1End->Enabled = false;
	TimerTrail1Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail2EndTimer(TObject *Sender)
{
	Trail2->Visible = true;

	Trail2->Position->X = F2_TrailX2;
	Trail2->Position->Y = F2_TrailY2;

	F2_Trail_i2 = F2_TrailX2;

	TimerTrail2End->Enabled = false;
	TimerTrail2Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail3EndTimer(TObject *Sender)
{
	Trail3->Visible = true;

	Trail3->Position->X = F2_TrailX3;
	Trail3->Position->Y = F2_TrailY3;

	F2_Trail_i3 = F2_TrailX2;

	TimerTrail3End->Enabled = false;
	TimerTrail3Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail4EndTimer(TObject *Sender)
{
	Trail4->Visible = true;

	Trail4->Position->X = F2_TrailX4;
	Trail4->Position->Y = F2_TrailY4;

	F2_Trail_i4 = F2_TrailX4;

	TimerTrail4End->Enabled = false;
	TimerTrail4Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail5EndTimer(TObject *Sender)
{
	Trail5->Visible = true;

	Trail5->Position->X = F2_TrailX5;
	Trail5->Position->Y = F2_TrailY5;

	F2_Trail_i5 = F2_TrailX5;

	TimerTrail5End->Enabled = false;
	TimerTrail5Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail6EndTimer(TObject *Sender)
{
	Trail6->Visible = true;

	Trail6->Position->X = F2_TrailX6;
	Trail6->Position->Y = F2_TrailY6;

	F2_Trail_i6 = F2_TrailX5;

	TimerTrail6End->Enabled = false;
	TimerTrail6Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail7EndTimer(TObject *Sender)
{
	Trail7->Visible = true;

	Trail7->Position->X = F2_TrailX7;
	Trail7->Position->Y = F2_TrailY7;

	F2_Trail_i7 = F2_TrailX7;

	TimerTrail7End->Enabled = false;
	TimerTrail7Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail8EndTimer(TObject *Sender)
{
	Trail8->Visible = true;

	Trail8->Position->X = F2_TrailX8;
	Trail8->Position->Y = F2_TrailY8;

	F2_Trail_i8 = F2_TrailX8;

	TimerTrail8End->Enabled = false;
	TimerTrail8Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail9EndTimer(TObject *Sender)
{
	Trail9->Visible = true;

	Trail9->Position->X = F2_TrailX9;
	Trail9->Position->Y = F2_TrailY9;

	F2_Trail_i9 = F2_TrailX9;

	TimerTrail9End->Enabled = false;
	TimerTrail9Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerTrail10EndTimer(TObject *Sender)
{
	Trail10->Visible = true;

	Trail10->Position->X = F2_TrailX10;
	Trail10->Position->Y = F2_TrailY10;

	F2_Trail_i10 = F2_TrailX10;

	TimerTrail10End->Enabled = false;
	TimerTrail10Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier3StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i3 > - 50)
		{
			F2_Barrier_i3--; F2_Barrier_i3--; F2_Barrier_i3--; F2_Barrier_i3--; F2_Barrier_i3--; F2_Barrier_i3--;

			Barrier3->Position->X = F2_Barrier_i3;

			if(F2_Barrier_i3 <= - 50)
			{
				Barrier3->Visible = false;
				TimerBarrier3Start->Enabled = false;
				TimerBarrier3End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier3EndTimer(TObject *Sender)
{
	Barrier3->Visible = true;

	Barrier3->Position->X = F2_BarrierX3;

	F2_Barrier_i3 = F2_BarrierX3;

	TimerBarrier3End->Enabled = false;
	TimerBarrier3Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier4StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i4 > - 50)
		{
			F2_Barrier_i4--; F2_Barrier_i4--; F2_Barrier_i4--; F2_Barrier_i4--; F2_Barrier_i4--; F2_Barrier_i4--;

			Barrier4->Position->X = F2_Barrier_i4;

			if(F2_Barrier_i4 <= - 50)
			{
				Barrier4->Visible = false;
				TimerBarrier4Start->Enabled = false;
				TimerBarrier4End->Interval = Random(1500);
				TimerBarrier4End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier4EndTimer(TObject *Sender)
{
	Barrier4->Visible = true;

	Barrier4->Position->X = F2_BarrierX4;

	F2_Barrier_i4 = F2_BarrierX4;

	TimerBarrier4End->Enabled = false;
	TimerBarrier4Start->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TimerBarrier5StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i5 > - 50)
		{   //x6
			F2_Barrier_i5--; F2_Barrier_i5--; F2_Barrier_i5--; F2_Barrier_i5--; F2_Barrier_i5--; F2_Barrier_i5--;

			Barrier5->Position->X = F2_Barrier_i5;

			if(F2_Barrier_i5 <= - 50)
			{
				Barrier5->Visible = false;
				TimerBarrier5Start->Enabled = false;
				TimerBarrier5End->Interval = Random(1500);
				TimerBarrier5End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier5EndTimer(TObject *Sender)
{
	Barrier5->Visible = true;

	Barrier5->Position->X = F2_BarrierX5;
	Barrier5->Position->Y = Form2->Height / 2 + Random(Form2->Height / 2 - 70); //Random от центра Form до начала нижнего Barrier

	F2_Barrier_i5 = F2_BarrierX5;

	TimerBarrier5End->Enabled = false;
	TimerBarrier5Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormResize(TObject *Sender)
{
	if(RESIZING == 1)
	{
		F2_RESIZE_COMPONENTS();
	}
	else
	{
		int i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier6StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i6 > - 100)
		{
			F2_Barrier_i6--; F2_Barrier_i6--; F2_Barrier_i6--; F2_Barrier_i6--;

			Barrier6->Position->X = F2_Barrier_i6;

			if(F2_Barrier_i6 <= - 100)
			{
				Barrier6->Visible = false;
				TimerBarrier6Start->Enabled = false;
				TimerBarrier6End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier6EndTimer(TObject *Sender)
{
	Barrier6->Visible = true;

	Barrier6->Position->X = F2_BarrierX6;

	F2_Barrier_i6 = F2_BarrierX6;

	TimerBarrier6End->Enabled = false;
	TimerBarrier6Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGameOverTimer(TObject *Sender)
{
	TimerGameOver->Enabled = false;

	//HIDE_COMPONENTS();

//Уведомляем игрока том что он проиграл
	TimerLabels->Interval = 5000;
	Label8->Visible = true;
	TimerLabels->Enabled = true;

	TimerGame->Enabled = false;
	TimerGame1->Enabled = false;
	TimerGame2->Enabled = false;
	TimerGame3->Enabled = false;
	TimerGame4->Enabled = false;
	TimerGame5->Enabled = false;
	TimerGame6->Enabled = false;
	TimerGame7->Enabled = false;
	TimerWin->Enabled = false;

	TimerDifficultStart->Enabled = false;
	TimerDifficult1->Enabled = false;
	TimerDifficult2->Enabled = false;
	TimerDifficult3->Enabled = false;
	TimerDifficult4->Enabled = false;
	TimerDifficult5->Enabled = false;
	TimerDifficult6->Enabled = false;

	Label1->Visible = false;
	Label2->Visible = false;
	Label3->Visible = false;
	Label4->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
	Label7->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGameTimer(TObject *Sender)
{
	GAME();
	F2_TRAIL();

//Даем игроку после появления 3 сек. неуязвимости, что бы он сразу не разбился
	TimerPlayerShield1Up->Enabled = true;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = true;
	MainSpherePlayer->Visible = true;

	TimerPlayerShield1End->Interval = 3000;
	TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
	TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом

//Делаем кнопку Щита - активной
	BtnPlayerShield->Enabled = true;
	BtnPlayerJump->Enabled = true;

//Включаем планеты
	TimerPlanet1End->Enabled = true;
	TimerPlanet2End->Enabled = true;

//Выключаем/включаем таймеры
	TimerGame->Enabled = false;
	TimerGame1->Enabled = true; //1 уровень сложности!

//Включаем движение преград...........
	F2_BARRIER();

	Form2->TimerBarrier3End->Enabled = true; //Для разноброса
	Form2->TimerBarrier4Start->Enabled = true;
	Form2->TimerBarrier5Start->Enabled = true;
	Form2->TimerBarrier6Start->Enabled = true;

	Form2->Barrier3->Visible = true;
	Form2->Barrier4->Visible = true;
	Form2->Barrier5->Visible = true;
	Form2->Barrier6->Visible = true;

//	Form2->TimerFly->Enabled = true; //Обрабатывает столкновения
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet1StartTimer(TObject *Sender)
{
	if(F2_Planet_i1 > - 100)
	{
		F2_Planet_i1--;

		Planet1->Position->X = F2_Planet_i1;

		if(F2_Planet_i1 <= - 100)
		{
			Planet1->Visible = false;
			TimerPlanet1Start->Enabled = false;
			TimerPlanet3End->Enabled = true; //Вкл. сл. планету
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet1EndTimer(TObject *Sender)
{
	Planet1->Visible = true;

	Planet1->Position->X = F2_PlanetX1;
	Planet1->Position->Y = 10 + Random(Form2->Height - Form2->Planet1->Height - 10);

	F2_Planet_i1 = F2_PlanetX1;

	TimerPlanet1End->Enabled = false;
	TimerPlanet1Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet2StartTimer(TObject *Sender)
{
	if(F2_Planet_i2 > - 100)
	{
		F2_Planet_i2--;

		Planet2->Position->X = F2_Planet_i2;

		if(F2_Planet_i2 <= - 100)
		{
			Planet2->Visible = false;
			TimerPlanet2Start->Enabled = false;
			TimerPlanet2End->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet2EndTimer(TObject *Sender)
{
	Planet2->Visible = true;

	Planet2->Position->X = F2_PlanetX1;
	Planet2->Position->Y = 10 + Random(Form2->Height - Form2->Planet2->Height - 10);

	F2_Planet_i2 = F2_PlanetX2;

	TimerPlanet2End->Enabled = false;
	TimerPlanet2Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet3StartTimer(TObject *Sender)
{
	if(F2_Planet_i3 > - 100)
	{
		F2_Planet_i3--;

		Planet3->Position->X = F2_Planet_i3;

		if(F2_Planet_i3 <= - 100)
		{
			Planet3->Visible = false;
			TimerPlanet3Start->Enabled = false;
			TimerPlanet4End->Enabled = true; //Вкл. сл. планету
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet3EndTimer(TObject *Sender)
{
	Planet3->Visible = true;

	Planet3->Position->X = F2_PlanetX3;
	Planet3->Position->Y = 10 + Random(Form2->Height - Form2->Planet3->Height - 10);

	F2_Planet_i3 = F2_PlanetX3;

	TimerPlanet3End->Enabled = false;
	TimerPlanet3Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet4StartTimer(TObject *Sender)
{
	if(F2_Planet_i4 > - 100)
	{
		F2_Planet_i4--; F2_Planet_i4--;

		Planet4->Position->X = F2_Planet_i4;

		if(F2_Planet_i4 <= - 100)
		{
			Planet4->Visible = false;
			TimerPlanet4Start->Enabled = false;
			TimerPlanet5End->Enabled = true; //Вкл. сл. планету
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet4EndTimer(TObject *Sender)
{
	Planet4->Visible = true;

	Planet4->Position->X = F2_PlanetX4;
	Planet4->Position->Y = 10 + Random(Form2->Height - Form2->Planet4->Height - 10);

	F2_Planet_i4 = F2_PlanetX4;

	TimerPlanet4End->Enabled = false;
	TimerPlanet4Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet5StartTimer(TObject *Sender)
{
	if(F2_Planet_i5 > - 200)
	{
		F2_Planet_i5--;

		Planet5->Position->X = F2_Planet_i5;

		if(F2_Planet_i5 <= - 200)
		{
			Planet5->Visible = false;
			TimerPlanet5Start->Enabled = false;
//			TimerPlanet1End->Enabled = true; //Вкл. первую плануту, тем самым задаем цикличность
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlanet5EndTimer(TObject *Sender)
{
	Planet5->Visible = true;

	Planet5->Position->X = F2_PlanetX5;
	Planet5->Position->Y = Random(Form2->Height - Form2->Planet5->Height);

	F2_Planet_i5 = F2_PlanetX5;

	TimerPlanet5End->Enabled = false;
	TimerPlanet5Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier7StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i7 > - 100)
		{   //x10
			F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--;
			F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--; F2_Barrier_i7--;

			Barrier7->Position->X = F2_Barrier_i7;

			if(F2_Barrier_i7 <= - 100)
			{
				Barrier7->Visible = false;
				TimerBarrier7Start->Enabled = false;
				TimerBarrier7End->Interval = Random(9000);
				TimerBarrier7End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier8StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i8 > - 100)
		{   //x12
			F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--;
			F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--; F2_Barrier_i8--;
			F2_Barrier_i8--;

			Barrier8->Position->X = F2_Barrier_i8;

			if(F2_Barrier_i8 <= - 100)
			{
				Barrier8->Visible = false;
				TimerBarrier8Start->Enabled = false;
				TimerBarrier8End->Interval = Random(5000);
				TimerBarrier8End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier9StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i9 > - 100)
		{   //x5
			F2_Barrier_i9--; F2_Barrier_i9--; F2_Barrier_i9--; F2_Barrier_i9--; F2_Barrier_i9--;

			Barrier9->Position->X = F2_Barrier_i9;

			if(F2_Barrier_i9 <= - 100)
			{
				Barrier9->Visible = false;
				TimerBarrier9Start->Enabled = false;
				TimerBarrier9End->Interval = Random(3500);
				TimerBarrier9End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier10StartTimer(TObject *Sender)
{
//	if(Form2->STATUS->Text == "RUN")
//	{
		if(F2_Barrier_i10 > - 100)
		{   //x13
			F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--;
			F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--;
			F2_Barrier_i10--; F2_Barrier_i10--; F2_Barrier_i10--;

			Barrier10->Position->X = F2_Barrier_i10;

			if(F2_Barrier_i10 <= - 100)
			{
				Barrier10->Visible = false;
				TimerBarrier10Start->Enabled = false;
				TimerBarrier10End->Interval = Random(2000);
				TimerBarrier10End->Enabled = true;
			}
		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier7EndTimer(TObject *Sender)
{
	Barrier7->Visible = true;

	Barrier7->Position->X = F2_BarrierX7;
	Barrier7->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	F2_Barrier_i7 = F2_BarrierX7;

	TimerBarrier7End->Enabled = false;
	TimerBarrier7Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier8EndTimer(TObject *Sender)
{
	Barrier8->Visible = true;

	Barrier8->Position->X = F2_BarrierX8;
	Barrier8->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	F2_Barrier_i8 = F2_BarrierX8;

	TimerBarrier8End->Enabled = false;
	TimerBarrier8Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier9EndTimer(TObject *Sender)
{
	Barrier9->Visible = true;

	Barrier9->Position->X = F2_BarrierX9;
	Barrier9->Position->Y = Form2->Barrier3->Height + Random(Form2->Height / 2 - Form2->Barrier4->Height); //Random от верхнего barrier до нижнего barrier

	F2_Barrier_i9 = F2_BarrierX9;

	TimerBarrier9End->Enabled = false;
	TimerBarrier9Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerBarrier10EndTimer(TObject *Sender)
{
	Barrier10->Visible = true;

	Barrier10->Position->X = F2_BarrierX10;
	Barrier10->Position->Y = Random(Form2->Height - Form2->Barrier4->Height); //Random от верха нижнего Barrier

	F2_Barrier_i10 = F2_BarrierX10;

	TimerBarrier10End->Enabled = false;
	TimerBarrier10Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame1Timer(TObject *Sender)
{
	Form2->Barrier1->Visible = true;
	Form2->TimerBarrier1Start->Enabled = true;

	TimerGame1->Enabled = false;
	TimerGame2->Enabled = true; //2 уровень сложности!
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame2Timer(TObject *Sender)
{
	Form2->Barrier5->Visible = true;
	Form2->TimerBarrier5Start->Enabled = true;

	TimerGame2->Enabled = false;
	TimerGame3->Enabled = true; //3 уровень сложности!
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame3Timer(TObject *Sender)
{
	Form2->Barrier2->Visible = true;
	Form2->TimerBarrier2Start->Enabled = true;

	TimerGame3->Enabled = false;
	TimerGame4->Enabled = true; //4 уровень сложности!

	TimerPlayerShield1Up->Enabled = true;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = true;

	TimerPlayerShield1End->Enabled = false; //что бы не было ошибок
	TimerPlayerShield1End->Interval = 3000; //Время неуязвимости
	TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
	TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame4Timer(TObject *Sender)
{
	Form2->Barrier7->Visible = true;
	Form2->TimerBarrier7Start->Enabled = true;

	TimerGame4->Enabled = false;
	TimerGame5->Enabled = true; //5 уровень сложности!

	TimerPlayerShield1Up->Enabled = true;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = true;

	TimerPlayerShield1End->Enabled = false; //что бы не было ошибок
	TimerPlayerShield1End->Interval = 6000; //Время неуязвимости
	TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
	TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame5Timer(TObject *Sender)
{
	Form2->Barrier8->Visible = true;
	Form2->TimerBarrier8Start->Enabled = true;

	TimerGame5->Enabled = false;
	TimerGame6->Enabled = true; //6 уровень сложности!

	TimerPlayerShield1Up->Enabled = true;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = true;

	TimerPlayerShield1End->Enabled = false; //что бы не было ошибок
	TimerPlayerShield1End->Interval = 7000; //Время неуязвимости
	TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
	TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame6Timer(TObject *Sender)
{
	Form2->Barrier9->Visible = true;
	Form2->TimerBarrier9Start->Enabled = true;

	TimerGame6->Enabled = false;
	TimerGame7->Enabled = true; //7 уровень сложности!

	TimerPlayerShield1Up->Enabled = true;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = true;

	TimerPlayerShield1End->Enabled = false; //что бы не было ошибок
	TimerPlayerShield1End->Interval = 9000; //Время неуязвимости
	TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
	TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerGame7Timer(TObject *Sender)
{
	Form2->Barrier10->Visible = true;
	Form2->TimerBarrier10Start->Enabled = true;

	TimerGame7->Enabled = false;
	TimerWin->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerWinTimer(TObject *Sender)
{
	Form2->Barrier10->Visible = false;
	Form2->TimerBarrier10Start->Enabled = false;
	Form2->TimerBarrier10End->Enabled = false;

	Form2->Barrier9->Visible = false;
	Form2->TimerBarrier9Start->Enabled = false;
	Form2->TimerBarrier9End->Enabled = false;

	Form2->Barrier8->Visible = false;
	Form2->TimerBarrier8Start->Enabled = false;
	Form2->TimerBarrier8End->Enabled = false;

	Form2->Barrier7->Visible = false;
	Form2->TimerBarrier7Start->Enabled = false;
	Form2->TimerBarrier7End->Enabled = false;

	Form2->Barrier2->Visible = false;
	Form2->TimerBarrier2Start->Enabled = false;
	Form2->TimerBarrier2End->Enabled = false;

	Form2->Barrier5->Visible = false;
	Form2->TimerBarrier5Start->Enabled = false;
	Form2->TimerBarrier5End->Enabled = false;

	Form2->Barrier1->Visible = false;
	Form2->TimerBarrier1Start->Enabled = false;
	Form2->TimerBarrier1End->Enabled = false;

	Form2->Barrier6->Visible = false;
	Form2->TimerBarrier6Start->Enabled = false;
	Form2->TimerBarrier6End->Enabled = false;

	Form2->Barrier3->Visible = false;
	Form2->TimerBarrier3Start->Enabled = false;
	Form2->TimerBarrier3End->Enabled = false;

	Form2->Barrier4->Visible = false;
	Form2->TimerBarrier4Start->Enabled = false;
	Form2->TimerBarrier4End->Enabled = false;

	TimerWin->Enabled = false;

//Отключаем силовые поля и бонусы...
	CD_SHIELD = 0;
	CdPlayerShield->Visible = false;
	BtnPlayerShield->Enabled = false;
	TimerPlayerShield1Cd->Enabled = false;
	TimerPlayerShield1Up->Enabled = false;
	PlayerShield->Visible = false;
	TimerPlayerShield1End->Enabled = false;

	JUMP = 0;
	CD_JUMP = 0;
	CdPlayerJump->Visible = false;
	BtnPlayerJump->Enabled = false;
	TimerPlayerJumpCd->Enabled = false;
	TimerPlayerJumpEnd->Enabled = false;
	TimerPlayerJumpDown->Enabled = false;
	TimerPlayerJumpStart->Enabled = false;

//Включаем заставку TO BE CONINUED...
	TimerSpereCenter->Enabled = true;
	TimerPortal1End->Enabled = true;
	TimerSpereFly->Enabled = true;
	TimerPortal1Up->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPortal1StartTimer(TObject *Sender)
{
	if(F2_Portal_i1 > - 400)
	{
		F2_Portal_i1--; F2_Portal_i1--;

		Portal->Position->X = F2_Portal_i1--;

		if(F2_Portal_i1 <= Form2->Width / 2 - Form2->Portal->Width / 2)
		{
			TimerPortal1Start->Enabled = false;
			Button2Click(Sender);
			TimerPortalHide->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{
	if(RESIZING == 1)
	{
		F2_RESIZE_COMPONENTS();
	}
	else
	{
		int i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormDeactivate(TObject *Sender)
{
	if(RESIZING == 1)
	{
		F2_RESIZE_COMPONENTS();
	}
	else
	{
		int i;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
	if(RESIZING == 1)
	{
		F2_RESIZE_COMPONENTS();
	}
	else
	{
		int i;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::TimerPortal1EndTimer(TObject *Sender)
{
	Portal->Visible = true;

	Portal->Position->X = F2_PortalX1;
	Portal->Position->Y = Form2->Height / 2 - Form2->Portal->Height / 2;

	F2_Portal_i1 = F2_PortalX1;

	TimerPortal1End->Enabled = false;
	TimerPortal1Start->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerSpereCenterTimer(TObject *Sender)
{
	if(MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2 > Form2->Height / 2)
	{
		F2_TRAIL();
		MainSpherePlayer->Position->Y = MainSpherePlayer->Position->Y - 1;

		if(MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2 == Form2->Height / 2)
		{
			TimerSpereCenter->Enabled = false;
		}
	}


	if(MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2 < Form2->Height / 2)
	{
		F2_TRAIL();
		MainSpherePlayer->Position->Y = MainSpherePlayer->Position->Y + 1;

		if(MainSpherePlayer->Position->Y + MainSpherePlayer->Height / 2 == Form2->Height / 2)
		{
			TimerSpereCenter->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerSpereFlyTimer(TObject *Sender)
{
	if(MainSpherePlayer->Position->X < Form2->Width / 2 - Form2->MainSpherePlayer->Width / 2)
	{
		F2_TRAIL();
		MainSpherePlayer->Position->X = MainSpherePlayer->Position->X + 1;

		if(MainSpherePlayer->Position->X == Form2->Width / 2 - Form2->MainSpherePlayer->Width / 2)
		{
			TimerSpereFly->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerInPortal1Timer(TObject *Sender)
{
//Всасываем шлейф для дальнейшего взрыва
	if(Trail1->Position->X < MainSpherePlayer->Position->X) { Trail1->Position->X++; }
	if(Trail2->Position->X < MainSpherePlayer->Position->X) { Trail2->Position->X++; }
	if(Trail3->Position->X < MainSpherePlayer->Position->X) { Trail3->Position->X++; }
	if(Trail4->Position->X < MainSpherePlayer->Position->X) { Trail4->Position->X++; }
	if(Trail5->Position->X < MainSpherePlayer->Position->X) { Trail5->Position->X++; }
	if(Trail6->Position->X < MainSpherePlayer->Position->X) { Trail6->Position->X++; }
	if(Trail7->Position->X < MainSpherePlayer->Position->X) { Trail7->Position->X++; }
	if(Trail8->Position->X < MainSpherePlayer->Position->X) { Trail8->Position->X++; }
	if(Trail9->Position->X < MainSpherePlayer->Position->X) { Trail9->Position->X++; Trail9->Position->X++; }
	if(Trail10->Position->X < MainSpherePlayer->Position->X) { Trail10->Position->X++; }

	if(Trail1->Position->Y < MainSpherePlayer->Position->Y) { Trail1->Position->Y++; } else { Trail1->Position->Y--; }
	if(Trail2->Position->Y < MainSpherePlayer->Position->Y) { Trail2->Position->Y++; } else { Trail2->Position->Y--; }
	if(Trail3->Position->Y < MainSpherePlayer->Position->Y) { Trail3->Position->Y++; } else { Trail3->Position->Y--; }
	if(Trail4->Position->Y < MainSpherePlayer->Position->Y) { Trail4->Position->Y++; } else { Trail4->Position->Y--; }
	if(Trail5->Position->Y < MainSpherePlayer->Position->Y) { Trail5->Position->Y++; } else { Trail5->Position->Y--; }
	if(Trail6->Position->Y < MainSpherePlayer->Position->Y) { Trail6->Position->Y++; } else { Trail6->Position->Y--; }
	if(Trail7->Position->Y < MainSpherePlayer->Position->Y) { Trail7->Position->Y++; } else { Trail7->Position->Y--; }
	if(Trail8->Position->Y < MainSpherePlayer->Position->Y) { Trail8->Position->Y++; } else { Trail8->Position->Y--; }
	if(Trail9->Position->Y < MainSpherePlayer->Position->Y) { Trail9->Position->Y++; Trail9->Position->Y++; } else { Trail9->Position->Y--; }
	if(Trail10->Position->Y < MainSpherePlayer->Position->Y) { Trail10->Position->Y++; } else { Trail10->Position->Y--; }

//Выключаем стягивание для взрыва
	if(Trail1->Position->X == MainSpherePlayer->Position->X &&
	   Trail2->Position->X == MainSpherePlayer->Position->X &&
	   Trail3->Position->X == MainSpherePlayer->Position->X &&
	   Trail4->Position->X == MainSpherePlayer->Position->X &&
	   Trail5->Position->X == MainSpherePlayer->Position->X &&
	   Trail6->Position->X == MainSpherePlayer->Position->X &&
	   Trail7->Position->X == MainSpherePlayer->Position->X &&
	   Trail8->Position->X == MainSpherePlayer->Position->X &&
	   Trail9->Position->X == MainSpherePlayer->Position->X &&
	   Trail10->Position->X == MainSpherePlayer->Position->X)
	{
		TimerInPortal1->Enabled = false;

		TimerTrail1Start->Enabled = false;
		TimerTrail2Start->Enabled = false;
		TimerTrail3Start->Enabled = false;
		TimerTrail4Start->Enabled = false;
		TimerTrail5Start->Enabled = false;
		TimerTrail6Start->Enabled = false;
		TimerTrail7Start->Enabled = false;
		TimerTrail8Start->Enabled = false;
		TimerTrail9Start->Enabled = false;
		TimerTrail10Start->Enabled = false;

		TimerTrail1End->Enabled = false;
		TimerTrail2End->Enabled = false;
		TimerTrail3End->Enabled = false;
		TimerTrail4End->Enabled = false;
		TimerTrail5End->Enabled = false;
		TimerTrail6End->Enabled = false;
		TimerTrail7End->Enabled = false;
		TimerTrail8End->Enabled = false;
		TimerTrail9End->Enabled = false;
		TimerTrail10End->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerInPortal2Timer(TObject *Sender)
{
//Сдуваем MainSpherePlayer
	if(MainSpherePlayer->Height > 17 && MainSpherePlayer->Width > 17)
	{
		MainSpherePlayer->Height--;
		MainSpherePlayer->Width--;

		MainSpherePlayer->Position->X++;
		MainSpherePlayer->Position->Y++;
	}

	if(MainSpherePlayer->Height <= 17 || MainSpherePlayer->Width <= 17)
	{
		STATUS->Text = "EXPLORE"; //Взрыв, столкновение

		TimerInPortal2->Enabled = false;
		TimerInPortal3->Enabled = true;

		Trail1->Visible = false;
		Trail2->Visible = false;
		Trail3->Visible = false;
		Trail4->Visible = false;
		Trail5->Visible = false;
		Trail6->Visible = false;
		Trail7->Visible = false;
		Trail8->Visible = false;
		Trail9->Visible = false;
		Trail10->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerInPortal3Timer(TObject *Sender)
{
		TimerInPortal3->Enabled = false;
		MainSpherePlayer->Visible = false;

		Trail1->Visible = true;
		Trail2->Visible = true;
		Trail3->Visible = true;
		Trail4->Visible = true;
		Trail5->Visible = true;
		Trail6->Visible = true;
		Trail7->Visible = true;
		Trail8->Visible = true;
		Trail9->Visible = true;
		Trail10->Visible = true;

		TimerTrail1Start->Enabled = true;
		TimerTrail2Start->Enabled = true;
		TimerTrail3Start->Enabled = true;
		TimerTrail4Start->Enabled = true;
		TimerTrail5Start->Enabled = true;
		TimerTrail6Start->Enabled = true;
		TimerTrail7Start->Enabled = true;
		TimerTrail8Start->Enabled = true;
		TimerTrail9Start->Enabled = true;
		TimerTrail10Start->Enabled = true;

		TimerTheEnd->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::TimerPortal1UpTimer(TObject *Sender)
{
	if(Portal->Height < F2_PortalY1 + 150)
	{
		Portal->Height++; Portal->Height++; Portal->Height++;
		Portal->Position->Y = Form2->Height / 2 - Form2->Portal->Height / 2;

		if(Portal->Height >= F2_PortalY1 + 150)
		{
			TimerPortal1Up->Enabled = false;
			TimerPortal1Down->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPortal1DownTimer(TObject *Sender)
{
	if(Portal->Height > F2_PortalY1)
	{
		Portal->Height--; Portal->Height--; Portal->Height--;
		Portal->Position->Y = Form2->Height / 2 - Form2->Portal->Height / 2;

		if(Portal->Height <= F2_PortalY1)
		{
			TimerPortal1Up->Enabled = true;
			TimerPortal1Down->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
//Делаем обработчик OnClick т.к. через таймер не корректно работает
	IN_PORTAL();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPortalHideTimer(TObject *Sender)
{
	TimerPortalHide->Enabled = false;
	Portal->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerShield1UpTimer(TObject *Sender)
{
	if(PlayerShield->Height < 250)
	{
		//x2
		PlayerShield->Height++; PlayerShield->Height++;

		Form2->PlayerShield->Position->X = Form2->MainSpherePlayer->Position->X - 40;
		Form2->PlayerShield->Position->Y = Form2->MainSpherePlayer->Position->Y - PlayerShield->Height / 2 + 17; //Подгоняем

		if(PlayerShield->Height >= 250)
		{
			TimerPlayerShield1Down->Enabled = true;
			TimerPlayerShield1Up->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerShield1DownTimer(TObject *Sender)
{
	if(PlayerShield->Height >= 150)
	{
		//x2
		PlayerShield->Height--; PlayerShield->Height--;

		Form2->PlayerShield->Position->X = Form2->MainSpherePlayer->Position->X - 40;
		Form2->PlayerShield->Position->Y = Form2->MainSpherePlayer->Position->Y - PlayerShield->Height / 2 + 17; //Подгоняем

		if(PlayerShield->Height <= 150)
		{
			TimerPlayerShield1Up->Enabled = true;
			TimerPlayerShield1Down->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPlayerShieldClick(TObject *Sender)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true && PlayerShield->Visible == false)
	{
		CdPlayerShield->Text = 9;
		CD_SHIELD = 9; //задаем перезарядку защитного щита в 18 сек
		CdPlayerShield->Visible = true;
		BtnPlayerShield->Enabled = false;
		TimerPlayerShield1Cd->Enabled = true; //Включаем таймер отсчета КД щита

		TimerPlayerShield1Up->Enabled = true;
		TimerPlayerShield1Down->Enabled = false;
		PlayerShield->Visible = true;

		TimerPlayerShield1End->Enabled = false; //что бы не было ошибок
		TimerPlayerShield1End->Interval = 3000; //Время неуязвимости
		TimerPlayerShield1End->Enabled = true; //Таймер который через N времени отключит щит
		TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
//Сбрасываем параметры компонентов
	RESET();
	HIDE_COMPONENTS();

//Делаем активными кнопки меню на Form1
	Form1->Btn_Continue->Enabled = true;
	Form1->Btn_Armory->Enabled = true;
	Form1->Btn_Exit->Enabled = true;
	Form1->Btn_NewGame->Enabled = true;

//ВКЛ анимацию...
	Form1->TimerStartAnimation->Enabled = true;

//ВКЛ мзыку на Form1
	Form1->TimerF1StartMusic->Enabled = true;
	Form1->TimerF1MusicRetry->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerShield1EndTimer(TObject *Sender)
{
	TimerPlayerShield1Up->Enabled = false;
	TimerPlayerShield1Down->Enabled = false;
	PlayerShield->Visible = false;

	TimerFly->Enabled = true; //Включаем таймер столкновений, тем самым делая уязвимость для игрока снова
	TimerPlayerShield1End->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPlayerJumpClick(TObject *Sender)
{
	if(Health1->Visible == true && MainSpherePlayer->Visible == true && PlayerShield->Visible == false)
	{
		JUMP = 0; //Для прыжка

		CD_JUMP = 3; //CD
		CdPlayerJump->Text = 3;
		CdPlayerJump->Visible = true;

		TimerPlayerJumpStart->Enabled = true;
		TimerPlayerJumpDown->Enabled = false;

		BtnPlayerJump->Enabled = false;
		TimerPlayerShield1Cd->Enabled = true; //Включаем таймер отсчета КД прыжка

		TimerPlayerJumpCd->Enabled = false;
		TimerPlayerJumpCd->Index = 8000;
		TimerPlayerJumpCd->Enabled = true;

		TimerFly->Enabled = false; //Отключаем таймер столкновений, тем самым делаем неуязвимость щитом
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerShield1CdTimer(TObject *Sender)
{
	CD_SHIELD--;
	CdPlayerShield->Text = CD_SHIELD;

	if(CD_SHIELD == 0)
	{
		CdPlayerShield->Visible = false;
		BtnPlayerShield->Enabled = true;
		TimerPlayerShield1Cd->Enabled = false;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::TimerPlayerJumpStartTimer(TObject *Sender)
{
	if(MainSpherePlayer->Height > 15 && MainSpherePlayer->Width > 35)
	{
		MainSpherePlayer->Height--;
		MainSpherePlayer->Width--; MainSpherePlayer->Width--;

		Form2->MainSpherePlayer->Position->X++; Form2->MainSpherePlayer->Position->X++;
		Form2->MainSpherePlayer->Position->Y++;

		if(MainSpherePlayer->Height <= 30 && MainSpherePlayer->Width <= 35)
		{
			JUMP++;

			TimerPlayerJumpStart->Enabled = false;
			TimerPlayerJumpDown->Enabled = true;

			if(JUMP == 2)
			{
				TimerPlayerJumpStart->Enabled = false;
				TimerPlayerJumpDown->Enabled = false;

				TimerPlayerJumpEnd->Enabled = false; //что бы не было ошибок
				TimerPlayerJumpEnd->Interval = 1000; //Время неуязвимости
				TimerPlayerJumpEnd->Enabled = true; //Таймер который через N времени отключит щит
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerJumpDownTimer(TObject *Sender)
{
	if(MainSpherePlayer->Height < 50 && MainSpherePlayer->Width < 75)
	{
		MainSpherePlayer->Height++;
		MainSpherePlayer->Width++; MainSpherePlayer->Width++;

		Form2->MainSpherePlayer->Position->X--; Form2->MainSpherePlayer->Position->X--;
		Form2->MainSpherePlayer->Position->Y--;

		if(MainSpherePlayer->Height == 50 && MainSpherePlayer->Width == 75)
		{
			JUMP++;

			TimerPlayerJumpStart->Enabled = true;
			TimerPlayerJumpDown->Enabled = false;

			if(JUMP == 2)
			{
				TimerPlayerJumpStart->Enabled = false;
				TimerPlayerJumpDown->Enabled = false;

				TimerPlayerJumpEnd->Enabled = false; //что бы не было ошибок
				TimerPlayerJumpEnd->Interval = 1000; //Время неуязвимости
				TimerPlayerJumpEnd->Enabled = true; //Таймер который через N времени отключит щит
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerJumpCdTimer(TObject *Sender)
{
	CD_JUMP--;
	CdPlayerJump->Text = CD_JUMP;

	if(CD_JUMP == 0)
	{
		CdPlayerJump->Visible = false;
		BtnPlayerJump->Enabled = true;
		TimerPlayerJumpCd->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerPlayerJumpEndTimer(TObject *Sender)
{
	TimerPlayerJumpDown->Enabled = false;
	TimerPlayerJumpStart->Enabled = false;

	TimerFly->Enabled = true; //Включаем таймер столкновений, тем самым делая уязвимость для игрока снова
	TimerPlayerJumpEnd->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key == vkHardwareBack)
	{
		Key = 0;

//Сбрасываем параметры компонентов
		RESET();
		HIDE_COMPONENTS();

//Делаем активными кнопки меню на Form1
//		Form1->Btn_Continue->Enabled = true;
//		Form1->Btn_Armory->Enabled = true;
		Form1->Btn_Exit->Enabled = true;
		Form1->Btn_NewGame->Enabled = true;

//ВКЛ анимацию...
		Form1->TimerStartAnimation->Enabled = true;

//ВКЛ музыку на Form1
		Form1->TimerF1StartMusic->Enabled = true;

		Form2->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerHealthTimer(TObject *Sender)
{
	switch(StrToInt(Form2->HEALTH->Text))
	{
//Вычитаем одну жизнь за столкновение
		case 2:
		{
			if(Health3->Position->Y > -50)
			{
				Health3->Position->Y--;

				if(Health3->Position->Y <= -50)
				{
					Form2->Health3->Visible = false;
					TimerHealth->Enabled = false;
				}
			}
			break;
		}

//Вычитаем одну жизнь за столкновение
		case 1:
		{
			if(Health2->Position->Y > -50)
			{
				Health2->Position->Y--;

				if(Health2->Position->Y <= -50)
				{
					Form2->Health2->Visible = false;
					TimerHealth->Enabled = false;
				}
			}
			break;
		}

//Game Over
		case 0:
		{
			if(Health1->Position->Y > -50)
			{
				Health1->Position->Y--;

				if(Health1->Position->Y <= -50)
				{
					Form2->Health1->Visible = false;
					TimerHealth->Enabled = false;
				}
			}
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerLabelsTimer(TObject *Sender)
{
	if(Label1->Visible == true) { Label1->Visible = false; 	HIDE_COMPONENTS(); RESET(); Form2->Close(); }
	if(Label2->Visible == true) { Label2->Visible = false; }
	if(Label3->Visible == true) { Label3->Visible = false; }
	if(Label4->Visible == true) { Label4->Visible = false; }
	if(Label5->Visible == true) { Label5->Visible = false; }
	if(Label6->Visible == true) { Label6->Visible = false; }
	if(Label7->Visible == true) { Label7->Visible = false; }
	if(Label8->Visible == true) { Label8->Visible = false; RESET(); Form2->Close(); }

	TimerLabels->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerExplosionTimer(TObject *Sender)
{
	MediaPlayer2->Stop();
	TimerExplosion->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerMusicTimer(TObject *Sender)
{
	MediaPlayer1->FileName = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetDocumentsPath()) + "Form2.mp3";
	MediaPlayer1->Play();

	TimerMusic->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficultStartTimer(TObject *Sender)
{
	TimerDifficultStart->Enabled = false;
	TimerDifficult1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult1Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	TimerLabels->Interval = 3000;
	Label2->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult2->Enabled = true;
	TimerDifficult1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult2Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	Label3->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult3->Enabled = true;
	TimerDifficult2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult3Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	Label4->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult4->Enabled = true;
	TimerDifficult3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult4Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	Label5->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult5->Enabled = true;
	TimerDifficult4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult5Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	Label6->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult6->Enabled = true;
	TimerDifficult5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerDifficult6Timer(TObject *Sender)
{
//Уведомляем игрока о сложности
	Label7->Visible = true;
	TimerLabels->Enabled = true;

	TimerDifficult6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartAnimationHPTimer(TObject *Sender)
{
	if(Form2->Health1->Position->Y < 4)
	{
		Form2->Health1->Position->Y++;
		Form2->Health2->Position->Y++;
		Form2->Health3->Position->Y++;

		if(Form2->Health1->Position->Y >= 4)
		{
			TimerStartAnimationHP->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerForResizingTimer(TObject *Sender)
{
	if(Form2->BtnPlayerUp->Position->Y >= Form2->Height - Form2->BtnPlayerDown->Height - 4 && Form2->BtnPlayerJump->Position->X >= 4 &&
	   Form2->BtnPlayerShield->Position->X <= Form2->Width - Form2->BtnPlayerShield->Width - 4 && Form2->BtnPlayerDown->Position->Y <= Form2->Height - Form2->BtnPlayerDown->Height - 4 &&
	   Form2->Health1->Position->Y >= 4 && Form2->Health2->Position->Y >= 4 && Form2->Health3->Position->Y >= 4)
	   {
			TimerForResizing->Enabled = false;
			RESIZING = 1;

			F2_RESIZE_COMPONENTS();
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartPositionTimer(TObject *Sender)
{
//Задаем видимость...
//Left side
	Form2->BtnPlayerUp->Visible = true;
	Form2->BtnPlayerJump->Visible = true;

//Right side
	Form2->BtnPlayerDown->Visible = true;
	Form2->BtnPlayerShield->Visible = true;

//Center
//HP...
	Form2->Health1->Visible = true;
	Form2->Health2->Visible = true;
	Form2->Health3->Visible = true;

//Задаем координаты...
//Left side
	Form2->BtnPlayerUp->Position->X = 4;
	Form2->BtnPlayerUp->Position->Y = Form2->Height + 70;

	Form2->BtnPlayerJump->Position->X = -120;
	Form2->BtnPlayerJump->Position->Y = Form2->Height - Form2->BtnPlayerUp->Height - 4 - Form2->BtnPlayerJump->Height;

//Right side
	Form2->BtnPlayerDown->Position->X = Form2->Width - Form2->BtnPlayerDown->Width - 4;
	Form2->BtnPlayerDown->Position->Y = Form2->Height + 70;

	Form2->BtnPlayerShield->Position->X = Form2->Width + 120;
	Form2->BtnPlayerShield->Position->Y = Form2->Height - Form2->BtnPlayerDown->Height - 4 - Form2->BtnPlayerShield->Height;

//Center
//HP...
	Form2->Health2->Position->X = Form2->Width / 2 - Form2->Health2->Width / 2;
	Form2->Health2->Position->Y = -55;

	Form2->Health1->Position->X = Form2->Health2->Position->X - Form2->Health2->Width + 1;
	Form2->Health1->Position->Y = -55;

	Form2->Health3->Position->X = Form2->Health2->Position->X + Form2->Health2->Width - 1;
	Form2->Health3->Position->Y = -55;

//Выключаем таймер, запускаем анимацию
	TimerStartAnimationBtnUp->Enabled = true;
	TimerStartAnimationBtnJump->Enabled = true;

	TimerStartAnimationBtnDown->Enabled = true;
	TimerStartAnimationBtnShield->Enabled = true;

	TimerStartAnimationHP->Enabled = true;

//Проверяем компоненты и задаем Resize
	TimerForResizing->Enabled = true;

	TimerStartPosition->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartAnimationBtnUpTimer(TObject *Sender)
{
	if(Form2->BtnPlayerUp->Position->Y > Form2->Height - Form2->BtnPlayerDown->Height - 4)
	{
		Form2->BtnPlayerUp->Position->Y--;

		if(Form2->BtnPlayerUp->Position->Y <= Form2->Height - Form2->BtnPlayerDown->Height - 4)
		{
			TimerStartAnimationBtnUp->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartAnimationBtnJumpTimer(TObject *Sender)
{
	if(Form2->BtnPlayerJump->Position->X < 4)
	{
		Form2->BtnPlayerJump->Position->X++;

		if(Form2->BtnPlayerJump->Position->X >= 4)
		{
			TimerStartAnimationBtnJump->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartAnimationBtnShieldTimer(TObject *Sender)
{
	if(Form2->BtnPlayerShield->Position->X > Form2->Width - Form2->BtnPlayerShield->Width - 4)
	{
		Form2->BtnPlayerShield->Position->X--;

		if(Form2->BtnPlayerShield->Position->X <= Form2->Width - Form2->BtnPlayerShield->Width - 4)
		{
			TimerStartAnimationBtnShield->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerStartAnimationBtnDownTimer(TObject *Sender)
{
	if(Form2->BtnPlayerDown->Position->Y > Form2->Height - Form2->BtnPlayerDown->Height - 4)
	{
		Form2->BtnPlayerDown->Position->Y--;

		if(Form2->BtnPlayerDown->Position->Y <= Form2->Height - Form2->BtnPlayerDown->Height - 4)
		{
			TimerStartAnimationBtnUp->Enabled = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerTheEndTimer(TObject *Sender)
{
	TimerTheEnd->Enabled = false;

	Label1->Visible = true;
	TimerLabels->Enabled = true;
}
//---------------------------------------------------------------------------


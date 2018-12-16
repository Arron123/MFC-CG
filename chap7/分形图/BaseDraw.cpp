// BaseDraw.cpp: implementation of the CBaseDraw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseDraw.h"
#include "mmsystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBaseDraw::CBaseDraw()
{

}

CBaseDraw::~CBaseDraw()
{
}

//ªÒµ√¥∞ø⁄µƒ£¯◊¯±Í
void CBaseDraw::GetMaxX()
{
	CRect s_Rect;
	m_pDC->GetWindow()->GetClientRect(s_Rect);
	MaxX=s_Rect.right;
}

//ªÒµ√¥∞ø⁄µƒ£˘◊¯±Í
void CBaseDraw::GetMaxY()
{
	CRect s_Rect;
	m_pDC->GetWindow()->GetClientRect(s_Rect);
	MaxY=s_Rect.bottom;
}

//ª≠œﬂ∫Ø ˝
void CBaseDraw::Line(int x1,int y1,int x2,int y2)
{
	m_pDC->MoveTo(x1,y1);
	m_pDC->LineTo(x2,y2);

}

//ªª…´
COLORREF CBaseDraw::GetColor(int nColor)
{
	COLORREF color;
	switch(nColor)
	{
		case 1:
			color=RGB(0,0,0);	 //∫⁄
			break;
		case 2:
			color=RGB(255,0,0);  //∫Ï
			break;
		case 3:
			color=RGB(0,255,0);  //¬Ã
			break;
		case 4:
			color=RGB(0,0,255);  //¿∂
			break;
		case 5:
			color=RGB(255,255,0);//ª∆
			break;
		case 6:
			color=RGB(0,255,255);//«≥¿∂
			break;
		case 7:
			color=RGB(170,0,255);//◊œ
			break;
		case 8:
			color=RGB(188,145,71);//◊ÿ
			break;
		case 9:
			color=RGB(182,182,182);//ª“
			break;
		case 10:
			color=RGB(255,193,183);//◊©∫Ï
			break;
		case 11:
			color=RGB(215,243,183);//≤›¬Ã
			break;
		case 12:
			color=RGB(193,102,130);//≥‡∫Ï
			break;
		case 13:
			color=RGB(255,0,128);  //—Û∫Ï
			break;
		case 14:
			color=RGB(64,128,128);  //…Óª“
			break;
		case 15:
			color=RGB(0,128,192);    //∞µ¿∂
			break;
		default:
			break;
	}
	return(color);
}

//ªª…´
void CBaseDraw::SetColor(int nColor)
{	
	s_MyPen.DeleteObject();
	COLORREF color;
	switch(nColor)
	{
		case 1:
			color=RGB(0,0,0);	 //∫⁄
			break;
		case 2:
			color=RGB(255,0,0);  //∫Ï
			break;
		case 3:
			color=RGB(0,255,0);  //¬Ã
			break;
		case 4:
			color=RGB(0,0,255);  //¿∂
			break;
		case 5:
			color=RGB(255,255,0);//ª∆
			break;
		case 6:
			color=RGB(0,255,255);//«≥¿∂
			break;
		case 7:
			color=RGB(170,0,255);//◊œ
			break;
		case 8:
			color=RGB(188,145,71);//◊ÿ
			break;
		case 9:
			color=RGB(182,182,182);//ª“
			break;
		case 10:
			color=RGB(255,193,183);//◊©∫Ï
			break;
		case 11:
			color=RGB(215,243,183);//≤›¬Ã
			break;
		case 12:
			color=RGB(193,102,130);//≥‡∫Ï
			break;
		case 13:
			color=RGB(255,0,128);  //—Û∫Ï
			break;
		case 14:
			color=RGB(64,128,128);  //…Óª“
			break;
		case 15:
			color=RGB(0,128,192);    //∞µ¿∂
			break;
		case 16:
			color=RGB(255,255,255);  //∞◊
			break;
		default:
			break;
	}
	s_MyPen.CreatePen(PS_SOLID,1,color);
	m_pOldPen=m_pDC->SelectObject(&s_MyPen);
}

//‘›Õ£
void CBaseDraw::sleep(DWORD dwDelayTime)
{
	DWORD dwTimeBegin,dwTimeEnd;
	dwTimeBegin=timeGetTime();
	do
	{
		dwTimeEnd=timeGetTime();
	}
	while(dwTimeEnd-dwTimeBegin<dwDelayTime);
}

void CBaseDraw::UserWindow(double F1,double F2,double F3,double F4,int nMove)
{
	WX1=F1;
	WX2=F2;
	WY1=F3;
	WY2=F4;
	XRate=(MaxX-nMove*2)/(WX2-WX1);
	YRate=(MaxY-nMove*2)/(WY2-WY1);
	m_pDC->SetViewportOrg(nMove,nMove);
}

void CBaseDraw::WMoveTo(double x,double y)
{  
   XP1=x;
   YP1=y;
   WLineTo(x, y);
}

void  CBaseDraw::WLineTo(double x,double y)
{
	XP2=x;
    YP2=y;
    WClip(XP1, YP1, XP2, YP2);
    XP1=XP2;
    YP1=YP2;
}


void  CBaseDraw::WClip(double X1, double Y1, double X2, double Y2)
{
	enum   {Empty, Left1, Right1, Bottom1, Top1}  C, C1, C2;
	double X, Y;
	int    XX1, YY1, XX2, YY2;
    C1 = Empty;
    C2 = Empty;
    if ( X1<WX1 )  C1 = Left1;
    if ( X1>WX2 )  C1 = Right1;
    if ( Y1<WY1 )  C1 = Bottom1;
    if ( Y1>WY2 )  C1 = Top1;
    if ( X2<WX1 )  C2 = Left1;
    if ( X2>WX2 )  C2 = Right1;
    if ( Y2<WY1 )  C2 = Bottom1;
    if ( Y2>WY2 )  C2 = Top1;
    while ( (C1!=Empty)|| (C2!=Empty) )
	{
		if ( (C1*C2)!=Empty )  exit(0);
		if ( C1==Empty )  C=C2 ;
		else C=C1;
		if ( Left1 == C	)
		{
			X=WX1;
			Y=Y1+(Y2-Y1)*(WX1-X1)/(X2-X1);
		}
		else if ( Right1 == C )
		{   
			X=WX2;
			Y=Y1+(Y2-Y1)*(WX2-X1)/(X2-X1);
		}
		else if ( Bottom1 == C )
		{
			Y=WY1;
			X=X1+(X2-X1)*(WY1-Y1)/(Y2-Y1);
		}
		else  /* ( Top1 == C  ) */
		{
			Y=WY2;
			X=X1+(X2-X1)*(WY2-Y1)/(Y2-Y1);
		}
		if ( C==C1 )
		{
			X1=X;
			Y1=Y;
			C1 = Empty;
			if ( X<WX1 )  C1 = Left1;
			if ( X>WX2 )  C1 = Right1;
			if ( Y<WY1 )  C1 = Bottom1;
			if ( Y>WY2 )  C1 = Top1;
		}
		else
		{
			X2=X;
			Y2=Y;
			C2 = Empty;
			if ( X<WX1 )  C2 = Left1;
			if ( X>WX2 )  C2 = Right1;
			if ( Y<WY1 )  C2 = Bottom1;
			if ( Y>WY2 )  C2 = Top1;
		}
	}
	XX1 = int (0.5+(X1-WX1)*XRate);
	YY1 = int (0.5+(WY2-Y1)*YRate);
	XX2 = int (0.5+(X2-WX1)*XRate);
	YY2 = int (0.5+(WY2-Y2)*YRate);
	moveto(XX1, YY1);
	lineto(XX2, YY2);
}

//∂®µ„∫Ø ˝
void CBaseDraw::moveto(int x,int y)
{
	m_pDC->MoveTo(x,y);
}

//ª≠œﬂ∫Ø ˝
void CBaseDraw::lineto(int x,int y)
{
	m_pDC->LineTo(x,y);
}

//æØ∏Ê∫Ø ˝
void CBaseDraw::ShowError()
{
	AfxMessageBox("«Î∞¥Ã· æ∑∂Œß ‰»Î≤Œ ˝!");
}
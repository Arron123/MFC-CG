// Dragon.cpp: implementation of the CDragon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Dragon.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDragon::CDragon()
{
	
}

CDragon::~CDragon()
{
	m_pDC=NULL;
}

//构造函数　传入CDC的指针
CDragon::CDragon(CDC* pDC)
{
	m_pDC=pDC;
}

void CDragon::Draw()
{	
	int i;
	CString s_str;
	Step=STEP;
	Sign=1;
	m_pDC->GetWindow()->RedrawWindow();	
	//获得窗口的长宽大小
	GetMaxX();
	GetMaxY();
	XAxis[1]=MaxX/4;
	XAxis[STEP+1]=3*MaxX/4;
	YAxis[1]=2*MaxY/3;
	YAxis[STEP+1]=YAxis[1];
	SetColor(4);
	m_pDC->TextOut(100,20,"step 0");
	Line(XAxis[1],YAxis[1],XAxis[STEP+1],YAxis[STEP+1]);
	sleep(1);
	
	for (i=1;i<=(int)(log(STEP)/log(2)+0.5);++i)
	{
		m_pDC->GetWindow()->RedrawWindow();
		DDragon(i);
		s_str.Format("%s%d","step ",i);
		m_pDC->TextOut(100,20,s_str);
		Step=Step/2;
		//暂停
		sleep(400);
	}
	m_pDC->SelectObject(m_pOldPen);
	m_pDC->TextOut(30,20,"龙图");
}

void CDragon::DDragon(int nColor)
{
	int   i, j, dx, dy;
	j = Step / 2;
	if (nColor<=12)
		SetColor(nColor);
	else
		SetColor(1);
	i = 1;
    do 
    {
		dx = XAxis[Step+i] - XAxis[i];
        dy = YAxis[Step+i] - YAxis[i];
        Sign = Sign * -1;
        XAxis[i+j] = XAxis[i] + ( dx + ( dy * Sign )) / 2;
        YAxis[i+j] = YAxis[i] + ( dy - ( dx * Sign )) / 2;
		if ( nColor!= 0 )
	    {
			Line(XAxis[i], YAxis[i]-100, XAxis[i+j], YAxis[i+j]-100);
			Line(XAxis[i+j], YAxis[i+j]-100, XAxis[i+Step], YAxis[i+Step]-100);
		}
	    i = i + Step;
	}
	while ( i <= STEP );
}

// BaseDraw.h: interface for the CBaseDraw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEDRAW_H__CB43CA20_175A_11D4_81FF_94DCC6655E1C__INCLUDED_)
#define AFX_BASEDRAW_H__CB43CA20_175A_11D4_81FF_94DCC6655E1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define pi 3.141592654

class CBaseDraw  
{
public:
	CBaseDraw();
	virtual ~CBaseDraw();

protected:
	CDC* m_pDC;
	CPen* m_pOldPen;
	CPen s_MyPen;
	int MaxX,MaxY;
	double WX1,WX2,WY1,WY2,XP1,YP1,XP2,YP2,XRate,YRate;

protected:
	void GetMaxX();
	void GetMaxY();
	void SetColor(int nColor);
	void Line(int x1,int y1,int x2,int y2);
	void sleep(DWORD t);
	void UserWindow(double F1,double F2,double F3,double F4,int nMove);
	void WMoveTo(double x,double y);
	void WLineTo(double x,double y);
	void lineto(int x,int y);
	void moveto(int x,int y);
	void WClip(double X1,double Y1,double X2,double Y2);
	void ShowError();
	COLORREF GetColor(int nColor);
};

#endif // !defined(AFX_BASEDRAW_H__CB43CA20_175A_11D4_81FF_94DCC6655E1C__INCLUDED_)

// MyClass.cpp: implementation of the CMyClass class.        //MyClass基类的应用文件
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyClass.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyClass::CMyClass()
{

}

CMyClass::~CMyClass()
{

}

// 此函数赋图中顶点的齐次坐标值
void   CMyClass::ReadWorkpiece() 
{
	 
    X[1] = -20;  Y[1] = 20;   C[1] = 1;
	X[2] = -20;  Y[2] = 80;   C[2] = 1;
	X[3] = -40;  Y[3] = 60;   C[3] = 1;
	X[4] = -60;  Y[4] = 80;   C[4] = 1;
	X[5] = -60;  Y[5] =20;   C[5] = 1;
 	X[6] = -25;  Y[6] = 20;   C[6] = 1;
	X[7] = -25;  Y[7] = 70;   C[7] = 1;
	 X[8] = -40;  Y[8] = 50;   C[8] = 1;
	 X[9] = -55;  Y[9] = 70;   C[9] = 1;
	 X[10] = -55; Y[10] = 20;   C[10] = 1;
}

/***************************************************
* 此函数用于图形变换，用变换后顶 点的坐标计算公式*
*求其坐标值。顶点变换是由点的齐次坐标乘以变换矩阵得来的*
***************************************************/
void   CMyClass::Calculate(array2d B)
{
	  ReadWorkpiece();
	  
		 for (int i = 1;  i <= 10;  ++i )
	  {
	     XT[i] =X[i]*B[1][1]+Y[i]*B[2][1]+C[i]*B[3][1];
	     YT[i] =X[i]*B[1][2]+Y[i]*B[2][2]+C[i]*B[3][2];
	    	  }
}

//绘制
void CMyClass:: Display ()
{
	CFrameWnd* pWnd=(CFrameWnd*)AfxGetApp()->m_pMainWnd;
	CDC* pdc=pWnd->GetActiveView()->GetDC();
	CRect rr;
	::GetClientRect(pWnd->GetActiveView()->m_hWnd,rr);
	DrawView (pdc,rr);
	pWnd->GetActiveView()->ReleaseDC(pdc);
}

void CMyClass::DrawView (CDC* pdc,CRect rr)
{
	xx=rr.right/2;
	yy=rr.bottom/2;
	Calculate(A); 
	moveto(xx-XT[1], yy-YT[1],pdc);
	lineto(xx-XT[2], yy-YT[2],pdc);
	lineto(xx-XT[3], yy-YT[3],pdc);
	lineto(xx-XT[4], yy-YT[4],pdc);
	lineto(xx-XT[5], yy-YT[5],pdc);
	lineto(xx-XT[10], yy-YT[10],pdc);
	lineto(xx-XT[9], yy-YT[9],pdc);
	lineto(xx-XT[8], yy-YT[8],pdc);
	lineto(xx-XT[7], yy-YT[7],pdc);
	lineto(xx-XT[6], yy-YT[6],pdc);
	lineto(xx-XT[1], yy-YT[1],pdc);
	//绘制轴线
	moveto(xx-200, yy,pdc);
	lineto(xx+200, yy,pdc);
	moveto(xx, yy-200,pdc);
	lineto(xx, yy+200,pdc);

	Calculate(A1); // 作图形变换
	moveto(xx-XT[1], yy-YT[1],pdc);
	lineto(xx-XT[2], yy-YT[2],pdc);
	lineto(xx-XT[3], yy-YT[3],pdc);
	lineto(xx-XT[4], yy-YT[4],pdc);
	lineto(xx-XT[5], yy-YT[5],pdc);
	lineto(xx-XT[10], yy-YT[10],pdc);
	lineto(xx-XT[9], yy-YT[9],pdc);
	lineto(xx-XT[8], yy-YT[8],pdc);
	lineto(xx-XT[7], yy-YT[7],pdc);
	lineto(xx-XT[6], yy-YT[6],pdc);
	lineto(xx-XT[1], yy-YT[1],pdc);
}

//定义自己的定点函数，(x,y)为所要定的点
void CMyClass::moveto(double x,double y,CDC* pdc)
{
	pdc->MoveTo((int)x,(int)y);
}

//定义自己的画线函数，由当前点画至(x,y)处
void CMyClass::lineto(double x,double y,CDC* pdc)
{	
	pdc->LineTo((int)x,(int)y);
}

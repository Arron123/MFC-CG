// 二维图形变换View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "二维图形变换.h"

#include "二维图形变换Doc.h"
#include "二维图形变换View.h"
#include "MyClass.h"

#include "math.h"
#define PI  0.1745329252  /*    Pi/180     */

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_MIRROR_O, OnMirrorO)
	ON_COMMAND(ID_MIRROR_X, OnMirrorX)
	ON_COMMAND(ID_MIRROR_Y, OnMirrorY)
	ON_COMMAND(ID_ROTATION, OnRotation)
	ON_COMMAND(ID_ROTATIONXY, OnRotationxy)
	ON_COMMAND(ID_SCALING, OnScaling)
	ON_COMMAND(ID_SCALINGXY, OnScalingxy)
	ON_COMMAND(ID_TRANSLATION, OnTranslation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here/  绘制字符原图形
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A1[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A1[1][1]=1;
		my1.A1[2][2]=1;
		my1.A1[3][3]=1;
				
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		my1. Display ();


}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnMirrorO() 
{
	// TODO: Add your command handler code here
int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}

		//给图形变换矩阵赋值
		my1.A[1][1]=-1;
		my1.A[2][2]=-1;
		my1.A[3][3]=1;
	RedrawWindow();
		my1. Display ();	
}

void CMyView::OnMirrorX() 
{
	// TODO: Add your command handler code here
int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=1;
		my1.A[2][2]=-1;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CMyView::OnMirrorY() 
{
	// TODO: Add your command handler code here

		int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=-1;
		my1.A[2][2]=1;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();

}

void CMyView::OnRotation() 
{
	// TODO: Add your command handler code here
	int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=cos(PI*60);//旋转60度
		my1.A[1][2]=sin(PI*60);
		my1.A[2][1]=-sin(PI*60);
		my1.A[2][2]=cos(PI*60);
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CMyView::OnRotationxy() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A1[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A1[1][1]=1;
		my1.A1[2][2]=1;
		my1.A1[3][3]=1;
				
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=cos(PI*60);      
		my1.A[1][2]=sin(PI*60);
		my1.A[2][1]=-sin(PI*60);
		my1.A[2][2]=cos(PI*60);
		my1.A[3][1]=(1-cos(PI*60))*10-5*sin(PI*60);
		my1.A[3][2]=(1-cos(PI*60))*5+10*sin(PI*60);
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();	//	
	
}

void CMyView::OnScaling() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=5;
		my1.A[2][2]=2;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();

}

void CMyView::OnScalingxy() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象

		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A1[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A1[1][1]=1;
		my1.A1[2][2]=1;
		my1.A1[3][3]=1;
				
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值 ,相对于(5,10)，沿x、y轴分别变比2，2
		my1.A[1][1]=2;   
		my1.A[2][2]=2;
		my1.A[3][2]=-10;
		my1.A[3][1]=-5;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

void CMyView::OnTranslation() 
{
	// TODO: Add your command handler code here
		int i,j;
		CMyClass my1;  //构造新的CMyClass对象
		//将图形变换矩阵清零
		for ( i=1;i<=3;++i)
		{
			for ( j=1;j<=3;++j)
				my1.A[i][j]=0;
		}
		//给图形变换矩阵赋值
		my1.A[1][1]=1;
		my1.A[2][2]=1;
		my1.A[3][1]=15;
		my1.A[3][2]=45;
		my1.A[3][3]=1;
		RedrawWindow();
		my1. Display ();
	
}

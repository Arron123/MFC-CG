// 平面曲线图View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "平面曲线图.h"
#include "math.h"
#include "平面曲线图Doc.h"
#include "平面曲线图View.h"
#define sgn(x)((x)>0 ? 1:((x)==0 ? 0:(-1)))

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define nPoints 43234
/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_DRAW_LEAF, OnDrawLeaf)
	ON_COMMAND(ID_DRAW_ROSE, OnDrawRose)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
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
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
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

void CMyView::OnDrawLeaf() 
{	RedrawWindow();
	CClientDC *pdc=new CClientDC(this);
	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(0,0XFF,0));
    CPen *oldpen=(CPen*)pdc->SelectObject(&pen);
    
	int a,n,cx,cy,gx,gy,flag,k;
     double r,p,th,x,y,pi;
	 a=160;n=2; pi=3.14159;
	 cx=320;
	 cy=240;
	 flag=0;k=200;
	 for(p=1;p>=0.2;p-=0.2){
		 for(th=0;th<=2*pi+0.1;th+=pi/k){
			 r=abs(a*cos(n*th)*p);
			 x=int(r*cos(th));
			 y=int(r*sin(th));
			gx=int(cx+x);
			gy=int(cy+y);
			if(flag==0)  {pdc->MoveTo(gx,gy);}
			flag=1;
			pdc->LineTo(gx,gy);
		 }
		 flag=0;
	 }
pdc->DeleteDC();
	
}

void CMyView::OnDrawRose() 
{	RedrawWindow();
	int d,k,x1,x2,y1,y2;
	float pi,a,e;
	 CClientDC *pdc=new CClientDC(this);
	 CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(0xff,0,0));
	CPen *oldpen=(CPen*)pdc->SelectObject(&pen);  
	pi=3.14159;
	d=80;
	for(a=0;a<=2*pi;a+=pi/360) {
	e=d*(1+0.25*sin(4*a));
	e=e*(1+sin(8*a));
	x1=int(320+e*cos(a));
	x2=int(320+e*cos(a+pi/8)); //相对x1旋转π/8
	y1=int(200+e*sin(a));
	y2=int(200+e*sin(a+pi/8));//相对y1旋转π/8
	pdc->MoveTo(x1,y1);
	pdc->LineTo(x2,y2);
	}
	delete pdc;		
}

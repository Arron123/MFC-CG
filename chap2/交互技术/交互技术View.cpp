// 交互技术View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "交互技术.h"
#include "MessageDlg.h"
#include "交互技术Doc.h"
#include "交互技术View.h"

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
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_TEXT, OnDrawText)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_WM_CREATE()
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
//	m_dot_number=0;
 m_draw=false;
 m_bdoing=false;
  m_nwidth=1;
 m_color=RGB(0,0,255);
 m_pmdc = new CDC;
 m_pbmp = new CBitmap;

}


CMyView::~CMyView()
{delete m_pmdc;
 delete m_pbmp;
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
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	pDC->BitBlt(0,0,m_nmx,m_nmy,m_pmdc,0,0,SRCCOPY);
	pDC->SelectObject(poldbmp);
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

void CMyView::OnDrawLine() 
{
m_type=1;
	
}
void CMyView::OnDrawRect() 
{
m_type=2;
	
}
void CMyView::OnDrawText() 
{
m_type=3;
CDC*pDC=GetDC();
CMessageDlg dlg(this);
int TextLong;
if(dlg.DoModal()==IDOK)
{
	str=dlg.m_Text;		//得到标注的文字信息
TextLong=str.GetLength();	//标注文字的长度
	if(TextLong>0){
	
	pDC->TextOut(dot_begin.x,dot_begin.y,str);
	}
	else 
	{pDC->TextOut(dot_begin.x,dot_begin.y,"请输入文本");}

}
	ReleaseDC(pDC);
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{


	//获取设备环境
	CDC* pDC = GetDC() ;
	//将库存GDI对象选进设备环境
	pDC->SelectStockObject(NULL_BRUSH) ;
	m_draw=true;//开始绘图
	switch(m_type){//根据图形类型确定点坐标值
		case 1:
			dot_begin=point;//确定直线的始末端点值
			dot_end=point;
            break;
	case 2:
		if(m_bdoing)//判断是否处于绘图状态
		return;       
       {m_bdoing=true;
       SetCapture();//捕获鼠标输入
       m_pnew=point;//作为获得绘制矩形，圆角矩形，椭圆各函数中参数左上角点，和绘制直线的起始点值。
       m_pold=point;//作为获得绘制矩形，圆角矩形，椭圆各函数中参数右下角点，和绘制直线的结束点值。
		CBitmap* poldbmp;
		CPen pen;
	    pen.CreatePen(PS_SOLID,m_nwidth,m_color);
	    CPen* poldpen=m_pmdc->SelectObject(&pen);
		poldbmp=m_pmdc->SelectObject(m_pbmp);
		m_pmdc->SelectObject(poldpen);
     m_pmdc->SelectObject(poldbmp);
	}
		break;
	    case 3:
			dot_begin=point;
			break;
	  
		default:
			break;		
	}
	ReleaseDC(pDC) ;
	CView::OnLButtonDown(nFlags, point);
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	 m_draw=false;	
	CDC* pDC = GetDC() ;//获取设备环境
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_nwidth,m_color);		
	CPen* poldpen=m_pmdc->SelectObject(&pen);//将库存GDI对象选进设备环境	
	pDC->SelectStockObject(NULL_BRUSH) ;
	switch(m_type){
		case 1:
			dot_end=point;
			pDC->MoveTo(dot_begin.x,dot_begin.y);
			pDC->LineTo(dot_end.x,dot_end.y);
		break;
	   case 2:
			 if(m_bdoing)
			 {
			m_bdoing=false;
			CRect rect(m_pnew,m_pold);
			m_pmdc->Rectangle(rect);	
			Invalidate(false);//使窗口无效，触发OnDraw()函数，把整个内存区域图形显示到屏幕上
			m_pmdc->SelectObject(poldbmp);
			m_pmdc->SelectObject(poldpen);
			 }
			break;	
		default:
			break;
	}
ReleaseCapture();//释放鼠标捕获
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CDC* pDC = GetDC() ;
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_nwidth,m_color);
	CPen* poldpen=pDC->SelectObject(&pen);
	//设置绘图模式，并将先前的绘图模式加以保存

	CPoint pre_dot, cur_dot ;
	CStatusBar* pStatus=(CStatusBar*)
		AfxGetApp()->m_pMainWnd->GetDescendantWindow(ID_VIEW_STATUS_BAR);
	if(pStatus)
	{
		char tbuf[40];
		sprintf(tbuf,"(%8d,%8d)",point.x, point.y);
		//在状态条的第二个窗格中输出当前鼠标的位置
		pStatus->SetPaneText(1,tbuf);
	}	   
	switch(m_type){
		case 1:
			if(m_draw){	int nDrawmode = pDC->SetROP2(R2_NOT) ;
	//将库存GDI对象选进设备环境
	pDC->SelectStockObject(NULL_BRUSH) ;
				pre_dot = dot_end ;
		        cur_dot = point ;
				//绘制直线
				pDC->MoveTo(dot_begin.x,dot_begin.y);
                pDC->LineTo(pre_dot.x,pre_dot.y);
				pDC->MoveTo(dot_begin.x,dot_begin.y);
                pDC->LineTo(cur_dot.x,cur_dot.y);
				dot_end=point;				
				pDC->SetROP2(nDrawmode) ;}
			break;
         	
	   case 2:
		if (m_bdoing){
	CRect rectold(m_pold,m_pnew);//鼠标移动前的矩形区域
   
   
	rectold.NormalizeRect();//使矩形规格化，不计矩形顶点的相对位置
	rectold.InflateRect(m_nwidth,m_nwidth);//使原矩形的宽、高分别扩展m_nwidth,m_nwidth个像素
	pDC->BitBlt(rectold.left,rectold.top,rectold.Width(),rectold.Height(),m_pmdc,rectold.left,rectold.top,SRCCOPY);//把内存相对区域显示到相对区域的屏幕上
	CRect rectnew(m_pold,point);
	pDC->Rectangle(rectnew);
		}
     	break;

	default:		
		break;	}
		 
    m_pmdc->SelectObject(poldbmp);
	pDC->SelectObject(poldpen);
	m_pnew=point;	//恢复到先前的绘图模式
	ReleaseDC(pDC) ;	//释放掉不再使用的DC ；
	CView::OnMouseMove(nFlags, point);

}



int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_nmx=GetSystemMetrics(SM_CXSCREEN);
	m_nmy=GetSystemMetrics(SM_CXSCREEN);
	CDC* pDC=GetDC();
	m_pmdc->CreateCompatibleDC(pDC);
	m_pbmp->CreateCompatibleBitmap(pDC,m_nmx,m_nmy);//创建一个尺寸为m_nmx,m_nmy的与显示设备环境兼容的位图
    CBitmap* pOldbitmap=m_pmdc->SelectObject(m_pbmp);//把位图选入当前设备环境，同时保存原有位图

	CBrush brush;
	brush.CreateStockObject(WHITE_BRUSH);
	CRect rect(-1,-1,m_nmx,m_nmy);

	m_pmdc->FillRect(rect,&brush);
	m_pmdc->SelectObject(pOldbitmap);
	ReleaseDC(pDC);
	
	return 0;
}

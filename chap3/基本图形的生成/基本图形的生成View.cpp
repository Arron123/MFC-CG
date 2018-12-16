// 基本图形的生成View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "基本图形的生成.h"

#include "基本图形的生成Doc.h"
#include "基本图形的生成View.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define pi 0.017453

#define ROUND(a) ((int)(a+0.5))

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_DDALINE, OnDdaline)
	ON_COMMAND(ID_BRESENHAMLINE, OnBresenhamline)
	ON_COMMAND(ID_MIDPOINTCIRCLE, OnMidpointcircle)
	ON_COMMAND(ID_BRESENHAMCIRCLE, OnBresenhamcircle)
	ON_COMMAND(ID_MIDPOINTELLISPE, OnMidpointellispe)
	ON_COMMAND(ID_SCANFILL, OnScanfill)
	ON_COMMAND(ID_MIDPOINTLINE, OnMidpointline)
	ON_COMMAND(ID_SEEDFILL, OnSeedfill)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
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
	
	pDC->TextOut(20,5,"区域填充请注意:");
	pDC->TextOut(20,25,"1.双击鼠标左键，出现需填充的多边形，点击相关功能菜单实现区域填充");
	pDC->TextOut(20,50,"2.进行种子填充，需用鼠标右键，单击多边形内一点，作为开始填充的种子点");
	
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

void CMyView::OnDdaline() 
{
	CDC* pDC=GetDC();//获得设备指针
int xa=100, ya=300, xb=300, yb=200,c=RGB(255,0,0);//定义直线的两端点，直线颜色
  int x,y; 
  float dx, dy, k; 
  dx=(float)(xb-xa), dy=(float)(yb-ya); 
  k=dy/dx, y=ya; 
  if(abs(k)<1)
  {
  for (x=xa;x<=xb;x++) 
  {pDC->SetPixel (x,int(y+0.5),c); 
  y=y+k;}
  }
  if(abs(k)>=1)
  {
  for (y=ya;y<=yb;y++) 
  {pDC->SetPixel (int(x+0.5),y,c); 
  x=x+1/k;}
  } 
  ReleaseDC(pDC);
}


void CMyView::OnBresenhamline() 
{
	// TODO: Add your command handler code here
		CDC* pDC=GetDC();	
	int x1=100, y1=200, x2=350, y2=100,c=RGB(0,0,255);
    int i,s1,s2,interchange;
    float x,y,deltax,deltay,f,temp;
    x=x1;
    y=y1;
    deltax=abs(x2-x1);
    deltay=abs(y2-y1);
    if(x2-x1>=0) s1=1; else s1=-1;
    if(y2-y1>=0) s2=1; else s2=-1;

    if(deltay>deltax){
        temp=deltax;
        deltax=deltay;
        deltay=temp;
        interchange=1;
    }
    else interchange=0;
    f=2*deltay-deltax;
	pDC->SetPixel(x,y,c);
    for(i=1;i<=deltax;i++){
        
        if(f>=0){
            if(interchange==1) x+=s1;
			
            else y+=s2;
			pDC->SetPixel(x,y,c);
            f=f-2*deltax;
        }
        else{
            if(interchange==1) y+=s2;
            else x+=s1;
            f=f+2*deltay;
        }
    }
}

void CMyView::OnMidpointcircle() 
{
	// TODO: Add your command handler code here
CDC* pDC=GetDC();
  int xc=300, yc=300, r=50, c=RGB(0,255,0);
  int x,y;
  float d;
  x=0; y=r; d=(float)1.25-r;
  pDC->SetPixel ((xc+x),(yc+y),c);
  pDC->SetPixel ((xc-x),(yc+y),c);
  pDC->SetPixel ((xc+x),(yc-y),c);
  pDC->SetPixel ((xc-x),(yc-y),c);
  pDC->SetPixel ((xc+y),(yc+x),c);
  pDC->SetPixel ((xc-y),(yc+x),c);
  pDC->SetPixel ((xc+y),(yc-x),c);
  pDC->SetPixel ((xc-y),(yc-x),c);
  while(x<=y)
  { if(d<0) 	d+=2*x+3;
   else   { d+=2*(x-y)+5; y--;}
   x++;
  pDC->SetPixel ((xc+x),(yc+y),c);
  pDC->SetPixel ((xc-x),(yc+y),c);
  pDC->SetPixel ((xc+x),(yc-y),c);
  pDC->SetPixel ((xc-x),(yc-y),c);
  pDC->SetPixel ((xc+y),(yc+x),c);
  pDC->SetPixel ((xc-y),(yc+x),c);
  pDC->SetPixel ((xc+y),(yc-x),c);
  pDC->SetPixel ((xc-y),(yc-x),c);
  }
  ReleaseDC(pDC);
}

void CMyView::OnBresenhamcircle() 
{
	// TODO: Add your command handler code here
CDC* pDC=GetDC();
 int xc=300, yc=300, r=40, c=RGB(0,0,255);
  int x,y,p;

	 x=0,y=r,p=3-2*r;
while(x<y)
{
pDC->SetPixel(xc+x, yc+y, c);
pDC->SetPixel(xc-x, yc+y, c);
pDC->SetPixel(xc+x, yc-y, c);
pDC->SetPixel(xc-x, yc-y, c);
pDC->SetPixel(xc+y, yc+x, c);
pDC->SetPixel(xc-y, yc+x, c);
pDC->SetPixel(xc+y, yc-x, c);
pDC->SetPixel(xc-y, yc-x, c);
if (p<0)
p=p+4*x+6;
else
{
p=p+4*(x-y)+10;
y-=1;
} 
x+=1;
}
if(x==y)
pDC->SetPixel(xc+x, yc+y, c);
pDC->SetPixel(xc-x, yc+y, c);
pDC->SetPixel(xc+x, yc-y, c);
pDC->SetPixel(xc-x, yc-y, c);
pDC->SetPixel(xc+y, yc+x, c);
pDC->SetPixel(xc-y, yc+x, c);
pDC->SetPixel(xc+y, yc-x, c);
pDC->SetPixel(xc-y, yc-x, c);
ReleaseDC(pDC);
}



void CMyView::OnMidpointellispe() 
{
	// TODO: Add your command handler code here
CDC* pDC=GetDC();
	int a=200,b=100,xc=300,yc=200,c=RGB(255,0,0);
	int x,y;
	double d1,d2;
	x=0;y=b;
	d1=b*b+a*a*(-b+0.25);
	pDC->SetPixel(x+300,y+200,c);
	pDC->SetPixel(-x+300,y+200,c);
	pDC->SetPixel(x+300,-y+200,c);
	pDC->SetPixel(-x+300,-y+200,c);
	while(b*b*(x+1)<a*a*(y-0.5))
	{
		if(d1<0){
			d1+=b*b*(2*x+3);
			x++;}
		else
		{d1+=b*b*(2*x+3)+a*a*(-2*y+2);
		x++;y--;
		}
	pDC->SetPixel(x+xc,y+yc,c);
	pDC->SetPixel(-x+xc,y+yc,c);
	pDC->SetPixel(x+xc,-y+yc,c);
	pDC->SetPixel(-x+xc,-y+yc,c);
	}
	d2=sqrt(b*(x+0.5))+a*(y-1)-a*b;
	while(y>0)
	{
		if(d2<0){
			d2+=b*b*(2*x+2)+a*a*(-2*y+3);
			x++;y--;}
		else
		{d2+=a*a*(-2*y+3);
		y--;}
	pDC->SetPixel(x+xc,y+yc,c);
	pDC->SetPixel(-x+xc,y+yc,c);
	pDC->SetPixel(x+xc,-y+yc,c);
	pDC->SetPixel(-x+xc,-y+yc,c);
	}
	ReleaseDC(pDC);
}	


void CMyView::OnScanfill() 
{
	// TODO: Add your command handler code here

	CDC* pDC=GetDC();
	
	CPen pen(PS_SOLID,1,RGB(0,255,0));  //设置扫描线所用笔的属性
	CPen *old=pDC->SelectObject(&pen);
	
	int j,k,s=0;
	int p[9];  //每根扫描线交点
	int pmin,pmax;
		

	for(int i=0;i<8;i++)//建立边表
	{
		edge[i].dx=(float)(spt[i+1].x-spt[i].x)/(spt[i+1].y-spt[i].y);
		if(spt[i].y<=spt[i+1].y)
		{
			edge[i].num=i;
			edge[i].ymin=spt[i].y;
			edge[i].ymax=spt[i+1].y;
			edge[i].xmin=(float)spt[i].x;
			edge[i].xmax=(float)spt[i+1].x;
			}
		else{
			edge[i].num=i;
			edge[i].ymin=spt[i+1].y;
			edge[i].ymax=spt[i].y;
			edge[i].xmax=(float)spt[i].x;
			edge[i].xmin=(float)spt[i+1].x;
			}		
	}
	
	//求多边形的最大最小值
	for(int m=1;m<8;m++)
	{
		for(int n=0;n<8-m;n++)
		{
			if(spt[n].y<spt[n+1].y)
			{
			p0=spt[n];	spt[n]=spt[n+1];
			spt[n+1]=p0;
			}				
		}
	}
	pmax=spt[0].y,pmin=spt[7].y;

	for(int r=1;r<8;r++)	//边表edge排序
	{
		for(int q=0;q<8-r;q++)
		{
			if(edge[q].ymin<edge[q+1].ymin)
			{
			newedge[0]=edge[q];	edge[q]=edge[q+1];
			edge[q+1]=newedge[0];
			}				
		}
	}
		for(int scan=pmax-2;scan>pmin;scan--)  //扫描线遵守'“上开下闭”的原则
	{
		int b=0;
		k=s;
		  for(j=k;j<8;j++)
		{	
			if((scan>=edge[j].ymin)&&(scan<=edge[j].ymax))//判断扫描线与线段是否相交于顶点			  
			{
				if(scan==edge[j].ymax)
				{
					if(spt[edge[j].num+1].y<edge[j].ymax)
					{
									b++;
						p[b]=(int)edge[j].xmax;
					}
					if(spt[edge[j].num-1].y<edge[j].ymax)
					{
						b++;		
						p[b]=(int)edge[j].xmax;
					}			
				}
					if(scan==edge[j].ymin)
				{
					if(spt[edge[j].num+1].y>edge[j].ymin)
					{
									b++;
						p[b]=(int)edge[j].xmin;
					}
					if(spt[edge[j].num-1].y>edge[j].ymin)
					{
						b++;		
						p[b]=(int)edge[j].xmin;
					}			
				}	
				 if((scan>edge[j].ymin)&&(scan<edge[j].ymax))
				{
					b++;
					p[b]=(int)(edge[j].xmax+edge[j].dx*(scan-edge[j].ymax));
				}
			}
				
			if(scan<edge[j].ymin)          //建立新的活性边表
				 	s=j;                 
		  }		
		if(b>1)
		{					
				for(int u=1;u<=b;u++)
				{
				pDC->MoveTo(p[u],scan);
					u++;
				pDC->LineTo(p[u],scan);
				}				
		}		
	}

	pDC->MoveTo(150,200);
	pDC->LineTo(266,200);
	pDC->MoveTo(90,180);
	pDC->LineTo(273,180);
	pDC->SelectObject(old);
	ReleaseDC(pDC);
}

void CMyView::OnMidpointline() 
{
	// TODO: Add your command handler code here
CDC* pDC=GetDC();
int xa=300, ya=200, xb=450, yb=300,c=RGB(0,255,0);
 float a, b, d1, d2, d, x, y;
  a=ya-yb, b=xb-xa, d=2*a+b;
  d1=2*a, d2=2* (a+b);
  x=xa, y=ya;
  pDC->SetPixel(x, y, c);
  while (x<xb)
  { if (d<0)   {x++, y++, d+=d2; }
    else      {x++, d+=d1;}
    pDC->SetPixel(x, y, c);
  }  
ReleaseDC(pDC);
}

void CMyView::OnSeedfill() 
{
	// TODO: Add your command handler code here
	CWindowDC     dc (this);
	int fill=RGB(0,255,0);
	int boundary=RGB(255,0,0);
	CPoint pt=s_point;
	int x,y,pmin,pmax;
	//求多边形的最大最小值
	for(int m=1;m<8;m++)
	{
		for(int n=0;n<8-m;n++)
		{
			if(spt[n].y<spt[n+1].y)
			{
			p0=spt[n];	spt[n]=spt[n+1];
			spt[n+1]=p0;
			}				
		}
	}
	pmax=spt[0].y,pmin=spt[7].y;

	x=s_point.x;
	y=s_point.y;


	for(;y<pmax+1;y++)
	{
	int current=dc.GetPixel(x,y);
			
		while((current!=boundary)&&(current!=fill))
			{		
				dc.SetPixel(x,y,fill);
					x++;
		
				current=dc.GetPixel(x,y);			
			}
					
				x=s_point.x;
				x--;
				current=dc.GetPixel(x,y);

		while((current!=boundary)&&(current!=fill))
			{		
				dc.SetPixel(x,y,fill);
					x--;
		
				current=dc.GetPixel(x,y);			
			}
		x=s_point.x;
		current=dc.GetPixel(x,y);
	}

	x=s_point.x;
	y=s_point.y-1;
	for(;y>pmin+1;y--)
	{
	int current=dc.GetPixel(x,y);
			
		while((current!=boundary)&&(current!=fill))
			{		
				dc.SetPixel(x,y,fill);
					x++;
		
				current=dc.GetPixel(x,y);			
			}
					
				x=s_point.x;
				x--;
				current=dc.GetPixel(x,y);

		while((current!=boundary)&&(current!=fill))
			{		
				dc.SetPixel(x,y,fill);
					x--;
		
				current=dc.GetPixel(x,y);			
			}
		x=s_point.x;
		current=dc.GetPixel(x,y);
	}
}

void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	RedrawWindow();

	CDC* pDC=GetDC();
	CPen newpen(PS_SOLID,1,RGB(255,0,0));
	CPen *old=pDC->SelectObject(&newpen);

	spt[0]=CPoint(100,100);
	spt[1]=CPoint(300,100);
	spt[2]=CPoint(250,250);
	spt[3]=CPoint(100,250);	
	spt[4]=CPoint(150,200);
	spt[5]=CPoint(90,180);
	spt[6]=CPoint(150,150);
	spt[7]=CPoint(100,100);
	pDC->Polyline(spt,8);
	pDC->SelectObject(old);
	ReleaseDC(pDC);
	CView::OnLButtonDblClk(nFlags, point);
}

void CMyView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	s_point=point;
	CView::OnRButtonDown(nFlags, point);
}

// 曲线和曲面View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "曲线和曲面.h"
#include "math.h"
#include "曲线和曲面Doc.h"
#include "曲线和曲面View.h"
#define sgn(x)((x)>0 ? 1:((x)==0 ? 0:(-1)))
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define pi  3.14159
#define nPoints 43234
/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_AREA_BEZIER, OnAreaBezier)
	ON_COMMAND(ID_AREA_BSPLINE, OnAreaBspline)
	ON_COMMAND(ID_AREA_CONE, OnAreaCone)
	ON_COMMAND(ID_AREA_LINE, OnAreaLine)
	ON_COMMAND(ID_AREA_RING, OnAreaRing)
	ON_COMMAND(ID_AREA_ROTATION, OnAreaRotation)
	ON_COMMAND(ID_DRAW_3BEZIER, OnDraw3bezier)
	ON_COMMAND(ID_DRAW_3BSPLINE, OnDraw3bspline)
	ON_COMMAND(ID_DRAW_CYLINDER, OnDrawCylinder)
	ON_COMMAND(ID_DRAW_CYLINDER_CONE, OnDrawCylinderCone)
	ON_COMMAND(ID_DRAW_ROSE, OnDrawRose)
	ON_WM_KEYDOWN()
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
 l1=15;
	l5=300;m5=300;
    l3=l4=39;
    m3=m4=39;
	l2=80;m2=100;
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
void CMyView::creat_unit_matrix()
{
  for(i=0;i<4;i++)
 { for(j=0;j<4;j++)
 { v[i][j]=0;
  v[i][i]=1;}}
  return;
}
void CMyView::rota_x_y_z()
{
for(i=0;i<4;i++)
for(j=0;j<4;j++)
a[i][j]=0;
a[3][3]=1;
a[z0][z0]=1;
a1=z0+1;
if(a1==3){a1=0;}
a2=a1+1;
if(a2==3){a2=0;}
ct=cos(th);
st=sin(th);
a[a1][a1]=ct;
a[a2][a2]=ct;
a[a1][a2]=st;
a[a2][a1]=-st;
return;
}
void CMyView::mult_matrix()
{
 for(i=0;i<4;i++)
{ for(j=0;j<4;j++)
 {va=0;
 for(k=0;k<4;k++)
 {va=va+v[i][k]*a[k][j];}
 b[i][j]=va;}
	   }
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
 v[i][j]=b[i][j];
 return;
    }

void CMyView::creat_u_wt()
{
if(U==0)
{ u[0][0]=0;u[0][1]=0;u[0][2]=0;u[0][3]=1;}
else {
 for(j=0;j<4;j++)
	 
u[0][j]=pow(U,(3-j));
      }
if(W==0)
{ wt[0][0]=0;wt[1][0]=0;wt[2][0]=0;wt[3][0]=1;}
else {
for(j=0;j<4;j++)

wt[j][0]=pow(W,(3-j));
	}
    return; 
}
/*read data to matrices x,y,z*/
void CMyView::read_data()
{

x[0][0]=100;x[0][1]=140;x[0][2]=140;x[0][3]=100;
x[1][0]=180;x[1][1]=190;x[1][2]=190;x[1][3]=180;
x[2][0]=230;x[2][1]=220;x[2][2]=220;x[2][3]=230;
x[3][0]=310;x[3][1]=270;x[3][2]=270;x[3][3]=310;

y[0][0]=100;y[0][1]=170;y[0][2]=220;y[0][3]=290;
y[1][0]=100;y[1][1]=170;y[1][2]=220;y[1][3]=290;
y[2][0]=100;y[2][1]=170;y[2][2]=220;y[2][3]=290;
y[3][0]=100;y[3][1]=170;y[3][2]=220;y[3][3]=290;

z[0][0]=100;z[0][1]=150;z[0][2]=150;z[0][3]=100;
z[1][0]=180;z[1][1]=210;z[1][2]=210;z[1][3]=180;
z[2][0]=180;z[2][1]=210;z[2][2]=210;z[2][3]=180;
z[3][0]=100;z[3][1]=150;z[3][2]=150;z[3][3]=100;
}
void CMyView::XuanZhuan()
{
	RedrawWindow();
CClientDC *pdc=new CClientDC(this);
 CPen pen;
 pen.CreatePen(PS_SOLID,1,RGB(0,0xff,0x1f));
 CPen *oldpen=(CPen*)pdc->SelectObject(&pen);
pdc->TextOut(10,10,"按下键盘上“上”、“下”、“左”、“右”箭头可观看曲面生成效果。");
 pdc->TextOut(300,50,"旋转曲面");
double r[4][4],v[4][4],p[2],q[3];
 register int i,j;
 int zo;
 double xmin,xmax,ymin,ymax,kx,ky,angle,u,w;
 xmin=-11;xmax=2;ymin=-5.0;
 ymax=479.0*(xmax-xmin)/639.0+ymin;
 kx=639.0/(xmax-xmin);
 ky=479.0/(ymax-ymin);
 p[0]=4;p[1]=0.5; angle=3.1415926/8;zo=2;
 rot(zo,angle,v);
 angle=0; zo=0;
 rot(zo,angle,r);
 mult44(v,v,r);
  
 for(i=0;i<=l2;i++)
  {
  u=(double)i/l2;
  for(j=0;j<=m2;j++)
   {
   w=(double)j/m2;
   dzb3(u,w,p,q);
   zbbh(q,v,q);
   if(j==0) pdc->MoveTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   else pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   }
  }

 for(i=0;i<=m2;i++)
  {
  w=(double)i/m2;
  for(j=0;j<=l2;j++)
   {
   u=(double)j/l2;
   dzb3(u,w,p,q);
   zbbh(q,v,q);
   if(j==0) pdc->MoveTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   else pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   }
  }
  pdc->DeleteDC(); 
	
}
void CMyView::bspline_draw()
{
	RedrawWindow();
	CDC *pDC=new CClientDC(this);
    CBrush ff(RGB(255,255,255));
    CRect rcclient;
	GetClientRect(&rcclient);
	pDC->FillRect(rcclient,&ff);
 double qx,qy,qz,qw,ur;
    double sx[100][100],sy[100][100],sz[100][100],xx[100][100],yy[100][100];
	pDC->TextOut(280,50,"三次B样条曲面");
	pDC->TextOut(10,10,"按下键盘“上”、“下”、“左”、“右”上箭头可观看曲面效果");
/*graph location in screen and input px,py,pz matrix data*/
    CPen penSolid(PS_SOLID,1,RGB(0,200,0));
   CPen penRed(PS_SOLID,1,RGB(0,0,255));
   CPen *pOldPen=NULL;
   pOldPen=pDC->SelectObject(&penSolid);

/*graph location in screen&input matrix data file*/
    w1=-320, w2=130,h1=-110; 
h2=479*(w2-w1)/639+h1;
aa=639/(w2-w1);
bb=479/(h2-h1);
read_data();/*read data to matrices x,y,z*/
/*creat matrices f&ft*/
f[0][0]=-1;f[0][1]=3;f[0][2]=-3;f[0][3]=1;
f[1][0]=3;f[1][1]=-6;f[1][2]=3;f[1][3]=0;
f[2][0]=-3;f[2][1]=0;f[2][2]=3;f[2][3]=0;
f[3][0]=1;f[3][1]=4;f[3][2]=1;f[3][3]=0;
for(i=0;i<4;i++)
{  for(j=0;j<4;j++)
{  ft[i][j]=f[j][i];}}
/*creat axonometric transform matrix vv */
//*creat unit matrix*/
creat_unit_matrix();
th=pi/4;z0=2;
rota_x_y_z();/*rotate about z_axis*/
mult_matrix();
th=-0.73452;z0=0;
rota_x_y_z();/*rotate about x_axis*/
mult_matrix();
th=pi;z0=0;
rota_x_y_z();
mult_matrix();
th=-pi/2;z0=1;
rota_x_y_z();
mult_matrix();
th=-pi;z0=2;
rota_x_y_z();
mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
vv[i][j]=v[i][j];
/*find the components of the product of matrix f&p&ft*/
for(kk=0;kk<3;kk++)
{ for(i=0;i<4;i++)
 for(j=0;j<4;j++)
  v[i][j]=f[i][j];
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
     {switch(kk){
 case 0:a[i][j]=x[i][j];
      break;
 case 1:a[i][j]=y[i][j];
      break;
 case 2:a[i][j]=z[i][j];
      break;
 default:
     break;
   }
    }

mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
a[i][j]=ft[i][j];

mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
  { switch(kk){
 case 0:rx[i][j]=v[i][j];
	   break;
 case 1:ry[i][j]=v[i][j];
	   break;
 case 2:rz[i][j]=v[i][j];
	   break;
 default:
	   break;
       }
	}
	 }
/*find the coordinates of point on b model surface*/
for(i1=0;i1<l4+1;i1++)
 { U=(float)i1/l4;
for(j1=0;j1<m4+1;j1++)
  {  W=(float)j1/m4;
/*creat matrix u&wt*/
creat_u_wt();
/*find product q[1][4] of u&rx|ry|rz*/
for(kk=0;kk<3;kk++)
 {  for(j=0;j<4;j++)
  { ur=0;
for(k1=0;k1<4;k1++)
 { switch(kk){
case 0:ur=ur+u[0][k1]*rx[k1][j];
     break;
case 1:ur=ur+u[0][k1]*ry[k1][j];
     break;
case 2:ur=ur+u[0][k1]*rz[k1][j];
     break;
default:
     break;
   }
     }
q[0][j]=ur;
    }
/*find product of q&wt*/
qw=0;
for(k1=0;k1<4;k1++)
 {  qw=qw+q[0][k1]*wt[k1][0];
		}
  switch(kk){
case 0:qx=qw;
      break;
case 1:qy=qw;
      break;
case 2:qz=qw;
      break;
default:
      break;
     }
     }
/*caculating the coodinate of b model surface*/
sx[i1][j1]=qx*vv[0][0]+qy*vv[1][0]+qz*vv[2][0]+vv[3][0];
sy[i1][j1]=qx*vv[0][1]+qy*vv[1][1]+qz*vv[2][1]+vv[3][1];
sz[i1][j1]=qx*vv[0][2]+qy*vv[1][2]+qz*vv[2][2]+vv[3][2];

/*multify factor 1/36 and convert coordinate &extend graph 0.12 is min*/
sx[i1][j1]=1.0/36.0*sx[i1][j1]*36.0*0.12;
sy[i1][j1]=1.0/36.0*sy[i1][j1]*36.0*0.12;
sz[i1][j1]=1.0/36.0*sz[i1][j1]*36.0*0.12;

xx[i1][j1]=aa*(-sx[i1][j1]-w1);
yy[i1][j1]=bb*(h2-sz[i1][j1]);
if(j1==0)
{  pDC->MoveTo((int)xx[i1][j1]+200,(int)yy[i1][j1]-20);}
else{
//setcolor(EGA_WHITE);
	
pDC->LineTo((int)xx[i1][j1]+200,(int)yy[i1][j1]-20);
      }
	}
	  }

for(j1=0;j1<m4+1;j1++)
 {  for(i1=0;i1<l4+1;i1++)
{  if(i1==0)
{  pDC->MoveTo((int)xx[i1][j1]+200,(int)yy[i1][j1]-20);}
else {
   //setcolor(EGA_RED);
	pDC->SelectObject(&penRed);
   pDC->LineTo((int)xx[i1][j1]+200,(int)yy[i1][j1]-20);
   }
      }
	 }

	}

	
	
void CMyView::beier_draw()
{	
	RedrawWindow();
	CDC *pDC=new CClientDC(this);
   CBrush ff(RGB(255,255,255));
    CRect rcclient;
	GetClientRect(&rcclient);
	pDC->FillRect(rcclient,&ff);
	double qx,qy,qz,qw,ur;
   double  sx[100][100],sy[100][100],sz[100][100],xx[100][100],yy[100][100];
   /*graph location and input px,py,pz matrix data*/
    CPen penSolid(PS_SOLID,1,RGB(0,255,0));
   CPen penRed(PS_SOLID,1,RGB(0,0,255));
   CPen *pOldPen=NULL;
   pOldPen=pDC->SelectObject(&penSolid);
    pDC->TextOut(10,10,"按下键盘上“上”、“下”、“左”、“右”箭头可观看曲面生成效果。");
	pDC->TextOut(200,50,"双三次贝塞尔曲面");
	/*graph location in screen&input matrix data file*/
  w1=-219,w2=100,h1=-200;
   h2=479*(w2-w1)/639+h1;aa=639/(w2-w1);   bb=479/(h2-h1);
	read_data();
/*creat matrices n&nt*/
n[0][0]=-1;n[0][1]=3;n[0][2]=-3;n[0][3]=1;
n[1][0]=3;n[1][1]=-6;n[1][2]=3;n[1][3]=0;
n[2][0]=-3;n[2][1]=3;n[2][2]=0;n[2][3]=0;
n[3][0]=1;n[3][1]=0;n[3][2]=0;n[3][3]=0;
for(i=0;i<4;i++)
{  for(j=0;j<4;j++)
{  nt[i][j]=n[j][i];}}
/*creat axonometric transform matrix vv */

creat_unit_matrix();/*creat unit matrix*/
/*rotate about z_axis*/
th=pi/5;z0=2;
rota_x_y_z();
mult_matrix();
/*rotate about x_axis*/
th=-0.67452;z0=0;
rota_x_y_z();
mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
vv[i][j]=v[i][j];
/*find the components of the product of matrix n&p&nt*/
for(kk=0;kk<3;kk++)
{ for(i=0;i<4;i++)
 for(j=0;j<4;j++)
  v[i][j]=n[i][j];
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
     {switch(kk){
 case 0:a[i][j]=x[i][j];
      break;
 case 1:a[i][j]=y[i][j];
      break;
 case 2:a[i][j]=z[i][j];
      break;
 default:
     break;
   }
    }

mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
a[i][j]=nt[i][j];

mult_matrix();

for(i=0;i<4;i++)
for(j=0;j<4;j++)
  { switch(kk){
 case 0:rx[i][j]=v[i][j];
	   break;
 case 1:ry[i][j]=v[i][j];
	   break;
 case 2:rz[i][j]=v[i][j];
	   break;
 default:
	   break;
       }
	}
	 }
/*find the coordinates of point on beier surface*/
for(i1=0;i1<l3+1;i1++)
 { U=(float)i1/l3;
for(j1=0;j1<l3+1;j1++)
  {  W=(float)j1/l3;

creat_u_wt();/*creat matrix u&wt*/
/*find product q[1][4] of u&rx|ry|rz*/
for(kk=0;kk<3;kk++)
 {  for(j=0;j<4;j++)
  { ur=0;
for(k1=0;k1<4;k1++)
 { switch(kk){
case 0:ur=ur+u[0][k1]*rx[k1][j];
     break;
case 1:ur=ur+u[0][k1]*ry[k1][j];
     break;
case 2:ur=ur+u[0][k1]*rz[k1][j];
     break;
default:
     break;
   }
     }
q[0][j]=ur;
    }
/*find product of q&wt*/
qw=0;
for(k1=0;k1<4;k1++)
 {  qw=qw+q[0][k1]*wt[k1][0];
		}
  switch(kk){
case 0:qx=qw;
      break;
case 1:qy=qw;
      break;
case 2:qz=qw;
      break;
default:
      break;
     }
     }
/*caculating the coodinate of beier surface*/
sx[i1][j1]=qx*vv[0][0]+qy*vv[1][0]+qz*vv[2][0]+vv[3][0];
sy[i1][j1]=qx*vv[0][1]+qy*vv[1][1]+qz*vv[2][1]+vv[3][1];
sz[i1][j1]=qx*vv[0][2]+qy*vv[1][2]+qz*vv[2][2]+vv[3][2];

/*extend graph with multify factor 1.45*/
sx[i1][j1]=sx[i1][j1]*1.0;
sy[i1][j1]=sy[i1][j1]*1.0;
sz[i1][j1]=sz[i1][j1]*1.0;

xx[i1][j1]=aa*(-sx[i1][j1]-w1);
yy[i1][j1]=bb*(h2-sz[i1][j1]);
if(j1==0)
{  pDC->MoveTo((int)xx[i1][j1],(int)yy[i1][j1]);}
else{
//setcolor(EGA_WHITE);
pDC->LineTo((int)xx[i1][j1],(int)yy[i1][j1]);
      }
	}
	  }

for(j1=0;j1<m3+1;j1++)
 {  for(i1=0;i1<l3+1;i1++)
{  if(i1==0)
{ pDC->MoveTo((int)xx[i1][j1],(int)yy[i1][j1]);}
else {
   //setcolor(EGA_RED);
	pDC->SelectObject(&penRed);
   pDC->LineTo((int)xx[i1][j1],(int)yy[i1][j1]);
   }
      }
	 }
 }
 void CMyView::shuangchaqumian()
 {RedrawWindow();
	 CClientDC *pdc=new CClientDC(this);
   CPen pen;
   pen.CreatePen(PS_SOLID,1,RGB(0,0xff,0x1f));
   CPen *oldpen=(CPen*)pdc->SelectObject(&pen);
    pdc->TextOut(10,10,"按下键盘上“上”、“下”、“左”、“右”箭头可观看曲面生成效果。");
   pdc->TextOut(300,80,"双插值曲面");
	double r[4][4],v[4][4],p[4][3],q[3],o[3];
   int i,j;
   double angle;
   int zo;
   double xmin,xmax,ymin,ymax,kx,ky,dl,u,w;
   
   xmin=-2.2;xmax=1.5;ymin=-0.5;
   ymax=479.0*(xmax-xmin)/639.0+ymin;
   kx=639.0/(xmax-xmin);
   ky=479.0/(ymax-ymin);

   for(i=0;i<4;i++)
    for(j=0;j<3;j++)
     p[i][j]=0;
   p[0][0]=2;p[0][2]=3;
   p[1][1]=-1;
   p[2][1]=1;
   p[3][0]=-2;p[3][2]=3;

   unit44(v);
   angle=3.1415926/4;zo=2;
   rot(zo,angle,r);
   mult44(v,v,r);

   angle=(double)-atan(0.3); zo=0;
   rot(zo,angle,r);
   mult44(v,v,r);

  dl=(double)1/l1;
/////////////////////////////////////
   for(i=0;i<=l1;i++)
   {
     u=dl*i;
     w=0;
     dzb(u,w,p,q);
     zbbh(q,v,q);
     pdc->MoveTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
     w=1;
     dzb(u,w,p,q);
     zbbh(q,v,q);
     pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   }

   for(i=0;i<=l1;i++)
   {
     w=dl*i;
     u=0;
     dzb(u,w,p,q);
     zbbh(q,v,q);
     pdc->MoveTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
     u=1;
     dzb(u,w,p,q);
     zbbh(q,v,q);
     pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   }
   for(i=0;i<3;i++)
   {
     q[i]=0;
     zbbh(q,v,o);
     q[0]=2;
     zbbh(q,v,q);
	 pdc->MoveTo(df(kx,xmin,-o[0]),-df(ky,ymax,o[2]));
     //pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
     q[0]=0;q[1]=1.5;q[2]=0;
     zbbh(q,v,q);
	 pdc->MoveTo(df(kx,xmin,-o[0]),-df(ky,ymax,o[2]));
     //pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
     q[0]=0;q[1]=-1.5;q[2]=0;
     zbbh(q,v,q);
	 pdc->MoveTo(df(kx,xmin,-o[0]),-df(ky,ymax,o[2]));
     //pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
     q[0]=0;q[1]=0;q[2]=5;
     zbbh(q,v,q);
	 pdc->MoveTo(df(kx,xmin,-o[0]),-df(ky,ymax,o[2]));
     //pdc->LineTo(df(kx,xmin,-q[0]),-df(ky,ymax,q[2]));
   }
   pdc->DeleteDC(); 
 }
int CMyView::df(double k, double min, double x)
{
 int xx;
 xx=k*(x-min);
 return xx;
}

void * CMyView::unit44(double unit[][4])
{
 register int i,j;
  for(i=0;i<4;i++)
  {
  for(j=0;j<4;j++)
   {
   unit[i][j]=0;
   }
  unit[i][i]=1;
  }
  return(unit);

}

void * CMyView::dzb3(double u, double w, double in[2], double out[3])
{
 float theta;
 theta=2*3.1415926*w;
 out[0]=in[0]*in[0]*u*u/(4*in[1]);
 out[1]=in[0]*u*cos(theta);
 out[2]=in[0]*u*sin(theta);
 return(out);
}

void * CMyView::dzb(double u,double w,double in[4][3] ,double out[3])                    /*计算曲面上点的坐标*/
{
 register int i,j;
 double f[4];
 f[0]=(1-u)*(1-w);
 f[1]=(1-u)*w;
 f[2]=u*(1-w);
 f[3]=u*w;
 for(i=0;i<3;i++)
  out[i]=0;
 for(i=0;i<3;i++)
  for(j=0;j<4;j++)
   out[i]+=f[j]*in[j][i];
 return(out);
 }

void * CMyView::zbbh(double in[], double rot[][4], double out[])
{
 double _in[4],_out[4];
 register int i,j;
 for(i=0;i<3;i++)
  {
   _in[i]=in[i];
   _out[i]=(out[i]=0,out[i]);
  }
  _out[3]=(_in[3]=1,_in[3]);
 
 for(i=0;i<4;i++)
  {
  for(j=0;j<4;j++)
   _out[i]+=(_in[j])*rot[j][i];
  }
 for(i=0;i<3;i++)
  out[i]=_out[i];
 return(out);

}

void * CMyView::mult44(double out[][4], double left[][4], double right[][4])
{
 double temp[4][4];
 register int i,j,k;
 for(i=0;i<4;i++)
  {
  for(j=0;j<4;j++)
   {
   temp[i][j]=0;
   for(k=0;k<4;k++)
    {
    temp[i][j]+=left[i][k]*right[k][j];
    }
   }
  }
 for(i=0;i<4;i++)
  for(j=0;j<4;j++)
   out[i][j]=temp[i][j];
 return(out);

}

void * CMyView::rot(int zo, double th, double p[][4])
{
 register int i,j;
 for(i=0;i<4;i++)
  for(j=0;j<4;j++)
   p[i][j]=0;
 p[3][3]=1;
 p[zo][zo]=1;
 i=zo+1;
 if(i==3)i=0;
 j=i+1;
 if(j==3)j=0;
 p[j][j]=(p[i][i]=cos(th),p[i][i]);
 p[j][i]=(p[i][j]=sin(th),-p[i][j]);
 return(p);	
}
int CMyView::scx(double xj)
{
int x;
x=(int)(xj+xmax/2);
return(x);
}

int CMyView:: scy(double yj)
{
int y;
y=(int)ymax-(int)(yj+(ymax/2));
return(y);

}
float CMyView::ThreeBezier(int degree,float coeff[],double t)
{
	   float coeffa[10];
	   for(int i=0;i<=degree;i++)
		   coeffa[i]=coeff[i];

	   float t1=float(1.0-t);
	   for(int r=1;r<=degree;r++)
		   for(i=0;i<=degree-r;i++)
	   {
		   coeffa[i]=t1*coeffa[i]+t*coeffa[i+1];
	   }
	   return (coeffa[0]);
}
void CMyView::Tiso(float p0[3],float x0, float y0, float p[3])
{
	p[0]=0.7071*(p0[0]-p0[1])+x0;
	p[2]=0;
	p[1]=-0.4082*(p0[0]+p0[1])+0.8165*p0[2]+y0;
}
/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnAreaBezier() //Bezier曲面
{
member=3;
beier_draw();
}

void CMyView::OnAreaBspline() //B样条曲面
{
	member=4;
bspline_draw();
}

void CMyView::OnAreaCone() 
{
	RedrawWindow();
	CDC*pDC=GetDC();
	pDC->TextOut(200,80,"参数式形成圆锥面");
float p[3],pp[3],t=0,x0=300,y0=400,u=60,v=0;
p[0]=t*sin(u)*cos(v);
p[1]=t*sin(u)*sin(v);	
p[2]=t*cos(u);
Tiso(p,x0,y0,pp);
pDC->MoveTo(pp[0],pp[1]);
for(t=1;t<=300;t++)
{
	for(v=1;v<=360;v++)
	{
		p[0]=t*sin(u)*cos(v);
		p[1]=t*sin(u)*sin(v);	
		p[2]=t*cos(u);
		Tiso(p,x0,y0,pp);
		pDC->LineTo(pp[0],pp[1]);
		}
	}
ReleaseDC(pDC);
}

void CMyView::OnAreaLine() //双线性曲面
{
member=1;
shuangchaqumian();
}

void CMyView::OnAreaRing() 
{
	RedrawWindow();
	CDC*pDC=GetDC();
	pDC->TextOut(200,80,"圆环曲面");
	float pp0[2],p[3],pp[3],R,du=3.1415926/100,dv=3.1415926/50,x0=300,y0=100,u=0,v=0;
	pp0[0]=200,pp0[1]=200,R=50;
	p[0]=(pp0[0]+R*sin(u))*cos(v);
	p[1]=(pp0[0]+R*sin(u))*sin(v);	
	p[2]=pp0[1]+R*cos(u);
	Tiso(p,x0,y0,pp);
	pDC->MoveTo(pp[0],pp[1]);
	for(v=1;v<=360;v++)
	{
		for(u=1;u<=360;u++)
		{
			p[0]=(pp0[0]+R*sin(u))*cos(v);
			p[1]=(pp0[0]+R*sin(u))*sin(v);	
			p[2]=pp0[1]+R*cos(u);
			Tiso(p,x0,y0,pp);
			pDC->LineTo(pp[0],pp[1]);
		}
	}
	ReleaseDC(pDC);
}

void CMyView::OnAreaRotation() //旋转曲面
{
	member=2;
	XuanZhuan();
}

void CMyView::OnDraw3bezier() 
{	RedrawWindow();

	float coeff_x[4];
	float coeff_y[4];
	float points_x[nPoints+1];
	float points_y[nPoints+1];
	int degree,i,j;
	degree=3;
	CClientDC *pdc=new CClientDC(this);
	 CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(0,0XFF,0));
    CPen *oldpen=(CPen*)pdc->SelectObject(&pen);
	pdc->TextOut(200,150,"三次Bezier曲线");
	  double delt;

	  coeff_x[0]=10;
	  coeff_x[1]=30;
	  coeff_x[2]=40;
	  coeff_x[3]=40;

	  coeff_y[0]=10;
	  coeff_y[1]=5;
	  coeff_y[2]=13;
	  coeff_y[3]=30;
      pdc->MoveTo(110,110);
	 for(j=0;j<=degree;j++)
	pdc->LineTo(10+10*coeff_x[j],10+10*coeff_y[j]);	  
	   delt=float(1.0/nPoints);
	  double t=0.0;

      	pdc->MoveTo(110,110);
	  for(i=0;i<=nPoints;i++)
	  {
		  points_x[i]=ThreeBezier(degree,coeff_x,t);
		  points_y[i]=ThreeBezier(degree,coeff_y,t);
          t=t+delt;
		  pdc->LineTo(10+10*points_x[i],10+10*points_y[i]);

	  }

      delete pdc;
}

void CMyView::OnDraw3bspline() 
{	RedrawWindow();
	CClientDC *pdc=new CClientDC(this);
   CPen pen;
   pen.CreatePen(PS_SOLID,1,RGB(0,0XFF,0));
    CPen *oldpen=(CPen*)pdc->SelectObject(&pen);
	pdc->TextOut(100,50,"三次B样条曲线");
	int cx,cy,i,n;
	n=9;
	double t,t2,t3,a0,a1,a2,a3,b0,b1,b2,b3,dt,xa,ya;
	cx=10;
	cy=160;
	static int x[4]={30,60,120,220},y[4]={30,110,150,50};
	a0=(x[0]+4*x[1]+x[2])/6;
	a1=-(x[0]-x[2])/2;
	a2=(x[2]-2*x[1]+x[0])/2;
	a3=-(x[0]-3*x[1]+3*x[2]-x[3])/6;
	b0=(y[0]+4*y[1]+y[2])/6;
	b1=-(y[0]-y[2])/2;
	b2=(y[2]-2*y[1]+y[0])/2;
	b3=-(y[0]-3*y[1]+3*y[2]-y[3])/6;
	dt=1.0/n;

	for (i=0;i<=n;i++){
	 t=i*dt;
	 t2=t*t;
	 t3=t2*t;

	 xa=a0+a1*t+a2*t2+a3*t3+cx;
	 ya=cy-(b0+b1*t+b2*t2+b3*t3);
	if(i==0) pdc->MoveTo(xa,ya);
     else   pdc->LineTo(xa,ya);
}
pdc->DeleteDC();	// TODO: Add your command handler code here
	
}

void CMyView::OnDrawCylinder() 
{
	RedrawWindow();
	int i;
	float a=200,dt=3.14159/50.0,t=0,k=10.0;
	float x0=300,y0=150;
	float p[3],pp[3];
	p[0]=a;
	p[1]=p[2]=0.0;
	CDC*pDC=GetDC();
	Tiso(p,x0,y0,pp);
	pDC->MoveTo(pp[0],pp[1]);
	pDC->TextOut(300,150,"圆柱曲线");
	for(i=1;i<=300;i++)
	{
	t+=dt;
	
	p[0]=a*cos(t);
	p[1]=a*sin(t);
	p[2]=k*t;
	Tiso(p,x0,y0,pp);
	pDC->LineTo(pp[0],pp[1]);
	}
	ReleaseDC(pDC);
}

void CMyView::OnDrawCylinderCone() 
{
	RedrawWindow();
	int i;
	float k=5.0,dt=0.3,t=0.0;
	float x0=300,y0=50;
	float p[3],pp[3];
	p[0]=p[1]=p[2]=0.0;
	CDC*pDC=GetDC();
	Tiso(p,x0,y0,pp);
	pDC->MoveTo(pp[0],pp[1]);
	pDC->TextOut(200,150,"圆锥曲线");
	for(i=1;i<=270;i++)
	{
	t+=dt;
	p[0]=t*cos(t);
	p[1]=-t*sin(t);
	p[2]=k*t;
	Tiso(p,x0,y0,pp);
	pDC->LineTo(pp[0],pp[1]);
	}
	ReleaseDC(pDC);
		
}

void CMyView::OnDrawRose() 
{
	RedrawWindow();
	int i;
	float a=200,dt=3.14159/150.0,theta=0.0,q;
	float x0=300,y0=200;
	float p[3],pp[3];
	p[0]=p[1]=0.0;
	p[2]=a;
	CDC*pDC=GetDC();
	Tiso(p,x0,y0,pp);
	pDC->MoveTo(pp[0],pp[1]);
	pDC->TextOut(200,150,"三叶梅花线");
	for(i=1;i<=150;i++)
	{
	theta+=dt;
	q=a*sin(3.0*theta);
	p[0]=q*cos(theta);
	p[1]=q*sin(theta);
	p[2]=a*fabs(cos(3.0*theta));
	Tiso(p,x0,y0,pp);
	pDC->LineTo(pp[0],pp[1]);
	}
	ReleaseDC(pDC);	
}

void CMyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(member==1){
		switch(nChar)
		{			
		case VK_UP://上
			l1--; 
			shuangchaqumian();
			break;
		case VK_DOWN://下
			l1++;
			 shuangchaqumian();
			break;
		case VK_RIGHT://右
			m1--;
			shuangchaqumian();
			break;
		case VK_LEFT://左
			m1++;
			shuangchaqumian();
			break;
		default:
			break;
		}
	}
		if(member==2){
		switch(nChar)
		{			
		case VK_UP://上
			l2--; 
			XuanZhuan();
				break;
		case VK_DOWN://下
			l2=l2++;
			XuanZhuan();
			break;
		case VK_RIGHT://右
			m2=m2--;
			XuanZhuan();
			break;
		case VK_LEFT://左
			m2=m2++;
			XuanZhuan();
			break;
		default:
			break;
		}
		}
			if(member==3){
		switch(nChar)
		{			
		case VK_UP://上
		l3=l3--;
			beier_draw();
			break;
		case VK_DOWN://下
			l3=l3++;
			beier_draw();
			break;
		case VK_RIGHT://右
			m3=m3--;
			beier_draw();
			break;
		case VK_LEFT://左
			m3=m3++;
			beier_draw();
			break;
		default:
			break;
		}
			}
			if(member==4){
		switch(nChar)
		{			
		case VK_UP://上
			l4=l4--; 
			bspline_draw();	 
			break;
		case VK_DOWN://下
			l4=l4++;
			bspline_draw();
			break;
		case VK_RIGHT://右
			m4=m4--;
			bspline_draw();
			break;
		case VK_LEFT://左
			m4=m4++;
			bspline_draw();
			break;
		default:
			break;
		}
	
			}
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

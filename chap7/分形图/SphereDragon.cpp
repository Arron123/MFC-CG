// SphereDragon.cpp: implementation of the CVase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "分形图.h"
#include "SphereDragon.h"
#include "Math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSphereDragon::CSphereDragon()
{

}

CSphereDragon::~CSphereDragon()
{
	m_pDC=NULL;
}

CSphereDragon::CSphereDragon(CDC* pDC)
{
	m_pDC=pDC;
}

CSphereDragon::Draw()
{
	m_pDC->GetWindow()->RedrawWindow();
	int i,k,j,sign,step,l,m,n;
	double dx,dy,x[4097],y[4097];
	double cx,cy,tx,ty;
	double wtx,wty,wx,wy;
	double beta,alfa,r,wr;
	double d11[19],d22[19];
	double gx,gy,gz,wz;
	double dt1[4][3],dt2[4][3];
	double d1[4][3]={{-1,0,1},{-1,0,0},{0,0,0},{0,0,1}};
	double d2[4][3]={{-1,1,1},{-1,1,0},{0,1,0},{0,1,1}};

	GetMaxX();
	GetMaxY();
	tx=-20*pi/180;
	ty=0*pi/180;
	cx=200,cy=250,r=150;
	for(l=0;l<2;l++)
	{
		for(i=0;i<=18;i++)
		{
			if(l==0)
				beta=10*i*pi/180;
			else
				alfa=10*i*pi/180;
			for(j=0;j<=18;j++)
			{
				if(l==0) 
					alfa=10*j*pi/180;
				else beta=10*j*pi/180;
				gx=r*sin(alfa)*cos(beta);
				gz=r*sin(alfa)*sin(beta);
				gy=r*cos(alfa);
				d11[j]=gx*cos(ty)+gz*sin(ty)+cx;
				d22[j]=gx*sin(tx)*sin(ty)+gy*cos(tx)
					-gz*sin(tx)*cos(ty)+cy;
			}
			moveto(d11[0],d22[0]);
			SetColor(13);
			for(k=0;k<=18;k++) 
				lineto(d11[k],d22[k]);
		}
	}
	x[0]=100;
	y[0]=150;
	x[4096]=400;
	y[4096]=200;
	sign=1;
	for(i=0;i<12;i++)
	{
		k=1;
		for(j=0;j<i;++j) 
			k=k*2;
		step=4096/(2*k);
		for(j=1;j<=k;j++)
		{
			m=2*j*step;
			n=2*(j-1)*step;
			l=(2*j-1)*step;
			dx=x[m]-x[n];
			dy=y[m]-y[n];
			sign=sign*(-1);
			x[l]=x[n]+(dx+(dy*sign))/2;
			y[l]=y[n]+(dy-(dx*sign))/2;
		}
	}
	moveto((x[0]/1.6-180)/1.5+MaxX*5/6,(y[0]/1.6-60)/1.5+MaxY/10);
	m_pDC->SelectObject(m_pOldPen);
	SetColor(4);
	for(i=0;i<4097;i++)
	{
		x[i]=x[i]/1.6-180,y[i]=y[i]/1.6-60;
		lineto(x[i]/1.5+MaxX*5/6,y[i]/1.5+MaxY/10);
	}
	wx=x[0];
	wy=y[0];
	wtx=wx*cos(ty)+cx;
	wty=wx*sin(tx)*sin(ty)+wy*cos(ty)+cy;
	moveto(wtx,wty);
	m_pDC->SelectObject(m_pOldPen);
	SetColor(4);
	for(i=0;i<4097;i++)
	{
		wy=y[i]-50;
		if(x[i]<d1[2][0])  
			ty=350*pi/180;
		wx=x[i];
		wtx=wx*cos(ty);
		wty=wx*sin(tx)*sin(ty)+wy*cos(tx);
		lineto(wtx+cx,wty+cy);
	}

	m_pDC->SelectObject(m_pOldPen);
	m_pDC->TextOut(100,90,"球体表面分形映射图");
}
// 曲线和曲面View.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__1EAA4B84_BD1C_4F7E_85E8_3E11E276E72F__INCLUDED_)
#define AFX_VIEW_H__1EAA4B84_BD1C_4F7E_85E8_3E11E276E72F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:
	CMyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
public:

	void * rot(int zo,double th,double p[4][4]);
	void * mult44(double out[4][4],double left[4][4],double right[4][4]);
	void * zbbh(double in[3],double rot[4][4],double out[3]);
	void * dzb(double u,double w,double in[4][3],double out[3]);
    void * dzb3(double u,double w,double in[2],double out[3]);
	void * unit44(double unit[4][4]);
	int df(double k,double min,double x);
	 void creat_unit_matrix();
    void rota_x_y_z();
    void mult_matrix();
    void creat_u_wt();
	void XuanZhuan();
	int member;
	void bspline_draw();
	void shuangchaqumian();
	void read_data();
	void beier_draw();
    double  x[4][4],y[4][4],z[4][4],tt[4][4],mt[4][4],vv[4][4],a[4][4];
    double  n[4][4],nt[4][4];
   	double  f[4][4],ft[4][4];
    double  rx[4][4],ry[4][4],rz[4][4],u[1][4],q[1][4],wt[4][1],b[4][4];
    double  v[4][4];
	double w1,w2,h1,h2,aa,bb;
    int kk,i,j,i1,j1,k1,l1,m1,l2,m2,l3,m3,l4,m4,l5,m5,k;
    double pi,th,ct,st,va,U,W;
	int z0,a1,a2;
double xmax,ymax;
//	double ff[3][3];
	int scx(double xj);
	int scy(double yj);
   float ThreeBezier(int degree,float coeff[],double t);
   void Tiso(float p0[3],float x0, float y0, float p[3]);
	public:
	//变量说明:
	//P0为圆外一点坐标，C为圆的圆心坐标及半径，P为所求切线的法线系数。
	float p0[3],x0,y0,p[3];
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnAreaBezier();
	afx_msg void OnAreaBspline();
	afx_msg void OnAreaCone();
	afx_msg void OnAreaLine();
	afx_msg void OnAreaRing();
	afx_msg void OnAreaRotation();
	afx_msg void OnDraw3bezier();
	afx_msg void OnDraw3bspline();
	afx_msg void OnDrawCylinder();
	afx_msg void OnDrawCylinderCone();
	afx_msg void OnDrawRose();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 曲线和曲面View.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__1EAA4B84_BD1C_4F7E_85E8_3E11E276E72F__INCLUDED_)

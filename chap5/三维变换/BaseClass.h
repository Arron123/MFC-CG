// BaseClass.h: interface for the CMyClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseCLASS_H__6250EB80_113B_11D4_81FF_D19FE195501C__INCLUDED_)
#define AFX_BaseCLASS_H__6250EB80_113B_11D4_81FF_D19FE195501C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define      Scale        1.35

typedef  double   array2d[5][5];
typedef  double   array[24];

/***********************************************************
* 变量说明： Rol, Theta, Phi是视点在用户坐标系中的球坐标变 *
* 量，DE为视距。Aux1, Aux2, Aux3, Aux4, Aux5, Aux6, Aux7,  *
* Aux8是全局变量，用于存取计算用户坐标系点到观察坐标系点的 *
* 坐标值公式中的正余弦值。X, Y, Z, C, XP, YP, ZP, CP为一维 *
* 数组，存放立体顶点齐次坐标，XT, YT, ZT亦为一维数组，存放 *
* 立体顶点经变换后的坐标值。A, Ah, Aw二维数组用来接收轴测  *
* 图的变换矩阵与三视图的变换矩阵参数值。                   *
***********************************************************/

class CBaseClass  // 定义一个基类
{
public:
	double	  theta_y, phi_x, i_o, h_o;
	double     Rol, Theta, Phi, DE,x0, z0;
	double	  XProj,YProj,Aux1,Aux2,Aux3,Aux4,Aux5,Aux6,Aux7,Aux8;
	int       xx, yy;
	array     X, Y, Z, C, XT, YT, ZT,XP,YP,ZP,CP;
	array2d   A, A1,Ah, Aw;
public:
	CBaseClass();
	virtual ~CBaseClass();
	void ReadWorkpiece();
	void ReadCube();
	void Calculate(array2d B);
	void MCalculate(array2d B);
	void WCalculate(array2d B);
	void TransformMatrice();
	void Project(double x,double y,double z);
	void DrawText();
	void Display();
	void Drawve();
	void Drawvt();
	void Drawse();
	void DrawPers();
	void DrawViewV(CDC* pdc,CRect rr);
	void DrawViewH(CDC* pdc,CRect rr);
	void DrawViewW(CDC* pdc,CRect rr);
	void WLineTo(double x,double y,double z,CDC* pdc,int MaxX,int MaxY);
	void WMoveTo(double x,double y,double z,CDC* pdc,int MaxX,int MaxY);
	void moveto(double x,double y,CDC* pdc);
	void lineto(double x,double y,CDC* pdc);
	void DrawCube();
//	void DrawCube1();
};

#endif // !defined(AFX_MYCLASS_H__6250EB80_113B_11D4_81FF_D19FE195501C__INCLUDED_)

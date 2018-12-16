// MyClass.h: interface for the CMyClass class.        //MyClass基类的头文件
//
//////////////////////////////////////////////////////////////////////
typedef  double   array2d[5][5];
typedef  double   array[24];

/***********************************************************
* 变量说明： X, Y, C,为一维 数组，存放图形顶点齐次坐标，
XT, YT,亦为一维数组，存放图形顶点经变换后的坐标值。*
* A, A1二维数组用来接收变换矩阵。                   *
***********************************************************/

class CMyClass  // 定义一个基类
{
public:
	int       xx, yy;
	array     X, Y, Z, C, XT, YT;
	array2d   A1,A;
public:
	CMyClass();
	virtual ~CMyClass();
	void ReadWorkpiece();
	void Calculate(array2d B);
	void Display ();
	void DrawView (CDC* pdc,CRect rr);
	void moveto(double x,double y,CDC* pdc);
	void lineto(double x,double y,CDC* pdc);
};

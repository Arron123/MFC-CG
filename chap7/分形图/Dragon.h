// Dragon.h: interface for the CDragon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAGON2_H__CB43CA21_175A_11D4_81FF_94DCC6655E1C__INCLUDED_)
#define AFX_DRAGON2_H__CB43CA21_175A_11D4_81FF_94DCC6655E1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseDraw.h"

#define STEP 4096

//´ÓCBaseDraw¼Ì³Ð¶øÀ´	
class CDragon : public CBaseDraw  
{
public:
	CDragon();
	CDragon(CDC* pDC);
	virtual ~CDragon();

private:
	int XAxis[STEP+2],YAxis[STEP+2],Step,Sign;

public:
	void Draw();

private:
	void DDragon(int nColor);
};

#endif // !defined(AFX_DRAGON2_H__CB43CA21_175A_11D4_81FF_94DCC6655E1C__INCLUDED_)

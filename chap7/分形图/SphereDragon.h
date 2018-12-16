// SphereDragon.h: interface for the CVase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPHEREDRAGON_H__3C8FD720_1D17_11D4_81FF_C79AC7682828__INCLUDED_)
#define AFX_SPHEREDRAGON_H__3C8FD720_1D17_11D4_81FF_C79AC7682828__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseDraw.h"

class CSphereDragon : public CBaseDraw  
{
public:
	CSphereDragon();
	CSphereDragon(CDC* pDC);
	virtual ~CSphereDragon();

private:

public:
	Draw();

private:
};

#endif // !defined(AFX_SPHEREDRAGON_H__3C8FD720_1D17_11D4_81FF_C79AC7682828__INCLUDED_)

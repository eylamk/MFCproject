
#include "stdafx.h" 
#include "RectangleF.h"


IMPLEMENT_SERIAL(RectangleF, CObject, 1)


RectangleF::RectangleF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width)
	:Figure(p1,p2,lineColor,fillColor,width)
{
}


bool RectangleF::isInside(const CPoint& P) const
{
	if ((P1.x <= P.x && P1.y <= P.y && P2.x >= P.x && P2.y >= P.y) || (P2.x <= P.x && P2.y <= P.y && P1.x >= P.x && P1.y >= P.y))
		return true;
	return false;
}


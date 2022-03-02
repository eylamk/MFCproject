#include "stdafx.h"
#include "SquareF.h"

IMPLEMENT_SERIAL(SquareF, CObject, 3)

SquareF::SquareF(CPoint p1, CPoint p2, COLORREF lineColor,COLORREF fillColor,int width) :RectangleF(p1, p2, lineColor,fillColor,width)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}
void SquareF::Redefine(CPoint p1, CPoint p2)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}

#include "stdafx.h"
#include "RhombusF.h"

IMPLEMENT_SERIAL(RhombusF, CObject, 4)

RhombusF::RhombusF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width) :RectangleF(p1,p2, lineColor,fillColor,width)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}

void RhombusF::Redefine(CPoint p1, CPoint p2)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}

void RhombusF::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, width, lineColor);
	CBrush bGcolor;
	bGcolor.CreateSolidBrush(fillColor);
	dc->SelectObject(pen);
	dc->SelectObject(bGcolor);
	CPoint points[4];
	points[0] = P1;
	points[2].SetPoint(P1.x , 2*P2.y-P1.y);
	points[1] = P2;
	points[3].SetPoint(2*P1.x - P2.x, P2.y);
	dc->Polygon(points, 4);
}

bool RhombusF::isInside(const CPoint& P) const
{
	if ((P.x <=P2.x && P.x >= 2 * P1.x - P2.x && P.y >= P1.y && P.y <= 2 * P2.y - P1.y) || (P.x >= P2.x && P.x <= 2 * P1.x - P2.x && P.y <= P1.y && P.y >= 2 * P2.y - P1.y))
	return true;
	return false;
}

double RhombusF::getArea() {
	double a, b;
	if (RhombusF::P2.x > (2*RhombusF::P1.x - RhombusF::P2.x))
		a = RhombusF::P2.x - (2 * RhombusF::P1.x - RhombusF::P2.x);
	else
		a = (2 * RhombusF::P1.x - RhombusF::P2.x) - RhombusF::P2.x;

	if (RhombusF::P1.y > (2 * RhombusF::P2.y - RhombusF::P1.y))
		b = P1.y - (2 * RhombusF::P2.y - RhombusF::P1.y);
	else
		b = (2 * RhombusF::P2.y - RhombusF::P1.y) - P1.y ;
	return (a * b) / 2;
}





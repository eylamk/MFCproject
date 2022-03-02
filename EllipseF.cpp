
#include "stdafx.h"
#include "EllipseF.h"


IMPLEMENT_SERIAL(EllipseF, CObject, 1)


EllipseF::EllipseF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width)
	:Figure(p1, p2,lineColor,fillColor,width)
{
}
void EllipseF::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, width, lineColor);
	CBrush bGcolor;
	bGcolor.CreateSolidBrush(fillColor);
	dc->SelectObject(pen);
	dc->SelectObject(bGcolor);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}
double EllipseF::getPerimeter()
{
	double perimeter;
	CPoint center(abs(P2.x - P1.x) / 2, abs(P2.y - P1.y) / 2);
	CPoint b(center.x, P1.y);
	CPoint a(P2.x, center.y);
	perimeter = M_PI *( a.y + b.x);
	return perimeter;
}
double EllipseF::getArea()
{
	CPoint center(abs(P2.x - P1.x) / 2, abs(P2.y - P1.y) / 2);
	CPoint b(center.x, P1.y);
	CPoint a(P2.x, center.y);

	double area = b.x * a.y * M_PI;
	return area;
}

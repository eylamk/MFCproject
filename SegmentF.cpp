#include "stdafx.h"
#include "SegmentF.h"

IMPLEMENT_SERIAL(SegmentF, CObject, 6)

SegmentF::SegmentF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width)
	:EllipseF(p1, p2, lineColor, fillColor, width)
{
}
void SegmentF::Draw(CDC* dc) const {
	CPen pen(PS_SOLID, width, lineColor);
	CBrush bGcolor;
	bGcolor.CreateSolidBrush(fillColor);
	dc->SelectObject(pen);
	dc->SelectObject(bGcolor);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);
	

}
double SegmentF::getArea() {
	return 0;
}
double SegmentF::getPerimeter() {

	double a = SegmentF::P1.x - SegmentF::P2.x;
	double b = SegmentF::P1.y - SegmentF::P2.y;
	double ax = pow(a, 2);
	double bx = pow(b, 2);
	a = ax + bx;
	b = sqrt(a);

	return b;
}
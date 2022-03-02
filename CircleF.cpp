#include "stdafx.h"
#include "CircleF.h"
IMPLEMENT_SERIAL(CircleF, CObject, 5)
CircleF::CircleF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width) : EllipseF(p1, p2, lineColor, fillColor, width) {}

void CircleF::Redefine(CPoint p1, CPoint p2) {
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
	
}
double CircleF::getArea() {
	double radius;
	if (CircleF::P1.x > CircleF::P2.x)
		radius = (CircleF::P1.x - CircleF::P2.x) / 2;
	else
		radius = (CircleF::P2.x - CircleF::P1.x) / 2;
	return radius * radius * M_PI;

}
double CircleF::getPerimeter() {
	double radius;
	radius = abs((CircleF::P1.x - CircleF::P2.x)) / 2;
	return 2 * radius * M_PI;
}
#include "stdafx.h"  
#include "Figure.h"
#define M_PI 3.1415926535897931 

IMPLEMENT_SERIAL(Figure, CObject, 1)

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << lineColor;
		ar << fillColor;
		ar << width;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> lineColor;
		ar >> fillColor;
		ar >> width;
	}
}

bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
double Figure::getArea() {
	int a, b;
	if (P1.x > P2.x)
		a = P1.x - P2.x;
	else
		a = P2.x - P1.x;
	if (P1.y > P2.y)
		b = P1.y - P2.y;
	else
		b = P2.y - P1.y;
	return a * b;
}
double Figure::getPerimeter() {
	int a, b;
	if (P1.x > P2.x)
		a = P1.x - P2.x;
	else
		a = P2.x - P1.x;
	if (P1.y > P2.y)
		b = P1.y - P2.y;
	else
		b = P2.y - P1.y;
	return a + a + b + b;

}
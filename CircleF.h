#pragma once
#include "EllipseF.h"
class CircleF :
    public EllipseF
{
	DECLARE_SERIAL(CircleF)

public:
	CircleF() {};
	CircleF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width);
	void Redefine(CPoint p1, CPoint p2);
	double getArea();
	double getPerimeter();
};


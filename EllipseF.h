#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	DECLARE_SERIAL(EllipseF)  
public:
	EllipseF() {}
	EllipseF(CPoint p1, CPoint p2,COLORREF lineColor, COLORREF fillColor, int width);
	void Draw(CDC* dc) const;
	double getArea();
	double getPerimeter();
};

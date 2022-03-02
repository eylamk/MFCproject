#pragma once
#include "RectangleF.h"

class RhombusF : public RectangleF
{
	DECLARE_SERIAL(RhombusF)
	
public:
	RhombusF() {};
	RhombusF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width);
	void Redefine(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	bool isInside(const CPoint& P) const;
	double getArea();
};


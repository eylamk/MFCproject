#pragma once

#include "Figure.h"
class RectangleF : public Figure {
	
	DECLARE_SERIAL(RectangleF)  
	
public:
	
	RectangleF() {}
	RectangleF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width);
	bool isInside(const CPoint& P) const;
};


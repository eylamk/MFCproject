#pragma once
#include "RectangleF.h"
class SquareF : public RectangleF
{
	DECLARE_SERIAL(SquareF)    
public:
	SquareF() {}
	SquareF(CPoint p1, CPoint p2, COLORREF lineColor,COLORREF fillColor, int width);
	void Redefine(CPoint p1, CPoint p2);
};


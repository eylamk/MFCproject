#pragma once
#include "stdafx.h"
#define M_PI 3.1415926535897931 

class Figure: public CObject {
	DECLARE_SERIAL(Figure)
	CPoint P1;
	CPoint P2;
	COLORREF lineColor = 0x000000FF;
	COLORREF fillColor = 0x000000FF;
	int width = 1;
public:

	Figure() {
		this->lineColor = 0x000000FF;
		this->fillColor = 0x000000FF;
		this->width = 1;
	}
	
	Figure(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width):
		P1(p1), P2(p2)
	{
		this->lineColor = lineColor;
		this->fillColor = fillColor;
		this->width = width;
	}
	void Serialize(CArchive& ar);
	virtual void Draw(CDC *dc) const
	{
		CPen pen(PS_SOLID, width, lineColor);
		CBrush bGcolor;
		bGcolor.CreateSolidBrush(fillColor);
		dc->SelectObject(pen);
		dc->SelectObject(bGcolor);
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	}
	CPoint getP1() const 
	{ 
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual double getArea();
	virtual double getPerimeter();
};

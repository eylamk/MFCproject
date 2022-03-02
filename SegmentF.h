#pragma once
#include "EllipseF.h"
class SegmentF : public EllipseF
{
    DECLARE_SERIAL(SegmentF)
public:
    SegmentF() {}
    SegmentF(CPoint p1, CPoint p2, COLORREF lineColor, COLORREF fillColor, int width);
    void Draw(CDC* dc) const;
    double getArea();
    double getPerimeter();
};


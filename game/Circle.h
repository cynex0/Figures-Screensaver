#pragma once
#include "Figure.h"

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle(double x, double y, double r);
    virtual ~Circle();

    virtual void Draw();
};
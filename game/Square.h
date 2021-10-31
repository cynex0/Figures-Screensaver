#pragma once
#include "Figure.h"

class Square : public Figure
{
protected:
    double a_;
    double half;
public:
    Square(double x, double y, double a);
    virtual ~Square();

    virtual double getCollisionDistance();
    virtual void Draw();
};
#pragma once
#include "Figure.h"

class Square : public Figure
{
protected:
    double a_;
public:
    Square();
    Square(double x, double y, double a);
    virtual ~Square();

    virtual string ToString();
    virtual void FromString(string s);

    virtual double getCollisionDistance();
    virtual void Draw();
};

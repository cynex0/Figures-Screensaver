#pragma once
#include "Figure.h"

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle();
    Circle(double x, double y, double r);
    virtual ~Circle();

    void setR(double r);
    virtual string ToString();
    virtual void FromString(string s);

    virtual double getCollisionDistance();
    virtual void Draw();
};
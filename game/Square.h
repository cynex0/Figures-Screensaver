#pragma once
#include "Figure.h"
#include "AllegroApp.h"

class Square : public Figure
{
protected:
    double a_;
    double half;

public:
    Square();
    Square(double x, double y, double a);
    virtual ~Square();

    virtual string ToString();
    virtual void FromString(string s);

    double getCollisionDistance() override;
    void Draw() override;
};

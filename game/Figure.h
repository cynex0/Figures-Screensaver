#pragma once
#include "ISerializable.h"

class Figure: public ISerializable {
protected:
    double x_;
    double y_;
    double dx_;
    double dy_;

public:
    Figure();
    Figure(double x, double y);
    virtual ~Figure();

    void setX(double x);
    void setY(double y);

    virtual double getCollisionDistance() = 0;
    virtual void Draw();
    virtual void Move();
    virtual void CollideWithBounds();
    virtual void CollideWithFigure(Figure *other);
};
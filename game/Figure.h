#pragma once
#include "ISerializable.h"
#include "Point.h"

class Figure: public ISerializable {
protected:
    Point pos;
    Point vel;

public:
    Figure();
    Figure(double x, double y);
    Figure(Point pos_);
    virtual ~Figure();

    void setX(double x);
    void setY(double y);

    virtual double getCollisionDistance() = 0;
    virtual void Draw();
    virtual void Move();
    virtual void CollideWithBounds();
    virtual void CollideWithFigure(Figure *other);
};
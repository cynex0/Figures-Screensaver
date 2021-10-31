#pragma once

class Figure {
protected:
    double x_;
    double y_;
    double dx_;
    double dy_;

public:
    Figure(double x, double y);
    virtual ~Figure();

    virtual double getCollisionDistance() = 0;
    virtual void Draw();
    virtual void Move();
    virtual void CollideWithBounds();
    virtual void CollideWithFigure(Figure *other);
};
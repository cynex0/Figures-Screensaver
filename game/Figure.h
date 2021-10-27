#pragma once

class Figure {
protected:
    double x_;
    double y_;
    double dx_;
    double dy_;
    double center_to_edge;

public:
    Figure(double x, double y);
    virtual ~Figure();

    virtual void Draw();
    virtual void Move();
    virtual void CollideWithBounds();
    virtual void CollideWithFigure(Figure other);
};
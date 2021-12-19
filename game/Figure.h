#pragma once
#include "ISerializable.h"
#include "AllegroBase.hpp"
#include "Point.h"

class Figure: public ISerializable {
protected:
    Point pos;
    Point vel;
    ALLEGRO_COLOR color;

public:
    float movability;

    Figure();
    Figure(double x, double y);
    Figure(Point pos_);
    virtual ~Figure();

    void setPos(Point pos_);
    void setVel(Point vel_);
    void setColor(ALLEGRO_COLOR color_);

    virtual double getCollisionDistance() = 0;
    virtual void Draw() = 0;
    virtual void Move();
    virtual void CollideWithBounds();
    virtual void CollideWithFigure(Figure *other);
};
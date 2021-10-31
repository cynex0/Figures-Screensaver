#include "Circle.h"
#include "Figure.h"
#include "AllegroApp.h"

Circle::Circle(double x, double y, double r) :
    Figure(x, y),
    r_(r)
{}

Circle::~Circle() {};

double Circle::getCollisionDistance() {
    return r_;
}

void Circle::Draw()
{
    al_draw_filled_circle(x_, y_, r_, al_map_rgb(0, 255, 0));
}
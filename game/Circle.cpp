#include "Circle.h"
#include "Figure.h"
#include "AllegroApp.h"

Circle::Circle(double x, double y, double r) :
    Figure(x, y),
    r_(r)
{
    center_to_edge = r_;
}
Circle::~Circle() {};

void Circle::Draw()
{
    al_draw_filled_circle(x_, y_, r_, al_map_rgb(0, 255, 0));
}
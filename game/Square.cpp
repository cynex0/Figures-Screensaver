#include "Square.h"
#include "Figure.h"
#include "AllegroApp.h"
#include <iostream>


Square::Square(double x, double y, double a) :
    Figure(x, y),
    a_(a)
{
    half = a_ / 2;
}
Square::~Square() {};

double Square::getCollisionDistance()
{
    return half;
}

void Square::Draw()
{
    al_draw_filled_rectangle(x_ - half, y_ - half,
        x_ + half, y_ + half, al_map_rgb(255, 0, 0));
}
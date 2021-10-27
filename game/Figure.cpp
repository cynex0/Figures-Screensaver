#include "Figure.h"
#include "constants.h"
#include <windows.h>

Figure::Figure(double x, double y) :
    x_(x),
    y_(y)
{
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
    center_to_edge = 0;
}
Figure::~Figure() {};

void Figure::Draw() {};
void Figure::Move()
{
    x_ += dx_;
    y_ += dy_;
};

void Figure::CollideWithBounds() // for symmetrical figures only
{
    if (x_ - center_to_edge <= 0) {
        dx_ = -dx_;
        x_ = center_to_edge;
    }
    if (x_ + center_to_edge >= SCREEN_W) {
        dx_ = -dx_;
        x_ = SCREEN_W - center_to_edge;
    }
    if (y_ - center_to_edge <= 0) {
        dy_ = -dy_;
        y_ = center_to_edge;
    }
    if (y_ + center_to_edge >= SCREEN_H) {
        dy_ = -dy_;
        y_ = SCREEN_H - center_to_edge;
    }
}

void Figure::CollideWithFigure(Figure other) {
    if ((x_ - center_to_edge < other.x_ + other.center_to_edge) &&
        (x_ + center_to_edge > other.x_ - other.center_to_edge) &&
        (y_ - center_to_edge < other.y_ + other.center_to_edge) &&
        (y_ + center_to_edge > other.y_ - center_to_edge))
    {
        dx_ = -dx_; other.dx_ = -other.dx_;
        // dy_ *= -1; other.dy_ *= -1;

         /* conservation of energy (not working!)
         double new_dx1 = (center_to_edge - other.center_to_edge) * dx_ /
             (center_to_edge + other.center_to_edge);
         double new_dx2 = 2 * center_to_edge * dx_ /
             (center_to_edge + other.center_to_edge);
         double new_dy1 = (center_to_edge - other.center_to_edge) * dy_ /
             (center_to_edge + other.center_to_edge);
         double new_dy2 = 2 * center_to_edge * dy_ /
             (center_to_edge + other.center_to_edge);
         dx_ = new_dx1; other.dx_ = new_dx2;
         dy_ = new_dy1; other.dy_ = new_dy2;
         */
    }
}
#include "Figure.h"
#include "constants.h"
#include <windows.h>

Figure::Figure(double x, double y) :
    x_(x),
    y_(y)
{
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
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
    double collisionDistance = getCollisionDistance();

    if (x_ - collisionDistance <= 0) {
        dx_ = -dx_;
        x_ = collisionDistance;
    }
    if (x_ + collisionDistance >= SCREEN_W) {
        dx_ = -dx_;
        x_ = SCREEN_W - collisionDistance;
    }
    if (y_ - collisionDistance <= 0) {
        dy_ = -dy_;
        y_ = collisionDistance;
    }
    if (y_ + collisionDistance >= SCREEN_H) {
        dy_ = -dy_;
        y_ = SCREEN_H - collisionDistance;
    }
}

void Figure::CollideWithFigure(Figure *other) {
    double collisionDistance = getCollisionDistance();
    double other_collisionDistance = other->getCollisionDistance();

    if ((x_ - collisionDistance < other->x_ + other_collisionDistance) &&
        (x_ + collisionDistance > other->x_ - other_collisionDistance) &&
        (y_ - collisionDistance < other->y_ + other_collisionDistance) &&
        (y_ + collisionDistance > other->y_ - other_collisionDistance))
    {
        //switch velocities
        double temp_d = dx_;
        dx_ = other->dx_; other->dx_ = temp_d;
        
        //unstuck algorithm
        if (x_ < other->x_) {
            other->x_ = x_ + collisionDistance + other_collisionDistance;
        }
        else {
            other->x_ = x_ - collisionDistance - other_collisionDistance;
        }

        /*if (y_ > other->y_) {
            other->y_ = y_ - collisionDistance - other_collisionDistance;
        }
        else {
            other->y_ = y_ + collisionDistance + other_collisionDistance;
        }*/

         /*conservation of energy(not working!)
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
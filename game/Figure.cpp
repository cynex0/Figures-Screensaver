#include "Figure.h"
#include "constants.h"
#include <windows.h>

Figure::Figure():
    pos()
{
    vel = Point(10.0 - rand() % 21, 10.0 - rand() % 21);
}

Figure::Figure(double x, double y) :
    pos(x,y)
{
    vel = Point(10.0 - rand() % 21, 10.0 - rand() % 21);
}

Figure::Figure(Point pos_):
    pos(pos_)
{
    vel = Point(10.0 - rand() % 21, 10.0 - rand() % 21);
}

Figure::~Figure() {};

void Figure::setX(double x) {
    pos.x = x;
}

void Figure::setY(double y) {
    pos.y = y;
}

void Figure::Draw() {};
void Figure::Move()
{
    pos += vel;
};

void Figure::CollideWithBounds() // for symmetrical figures only
{
    double collisionDistance = getCollisionDistance();

    if (pos.x - collisionDistance <= 0) {
        vel.x = -vel.x;
        pos.x = collisionDistance;
    }
    if (pos.x + collisionDistance >= SCREEN_W) {
        vel.x = -vel.x;
        pos.x = SCREEN_W - collisionDistance;
    }
    if (pos.y - collisionDistance <= 0) {
        vel.y = -vel.y;
        pos.y = collisionDistance;
    }
    if (pos.y + collisionDistance >= SCREEN_H) {
        vel.y = -vel.y;
        pos.y = SCREEN_H - collisionDistance;
    }
}

void Figure::CollideWithFigure(Figure *other) {
    double collisionDistance = getCollisionDistance();
    double other_collisionDistance = other->getCollisionDistance();

    if ((pos.x - collisionDistance < other->pos.x + other_collisionDistance) &&
        (pos.x + collisionDistance > other->pos.x - other_collisionDistance) &&
        (pos.y - collisionDistance < other->pos.y + other_collisionDistance) &&
        (pos.y + collisionDistance > other->pos.y - other_collisionDistance))
    {
        //switch velocities
        Point temp_vel = vel;
        vel = other->vel;
        other->vel = temp_vel;
        
        //unstuck algorithm
        /*if (x_ < other->x_) {
            other->x_ = x_ + collisionDistance + other_collisionDistance;
        }
        else {
            other->x_ = x_ - collisionDistance - other_collisionDistance;
        }

        if (y_ > other->y_) {
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
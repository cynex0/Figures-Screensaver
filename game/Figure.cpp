#include "Figure.h"
#include "constants.h"
#include <windows.h>

Figure::Figure():
    pos()
{
    vel = Point(6.0 - rand() % 13, 6.0 - rand() % 13);
    color = al_map_rgb(0, 0, 0);
}

Figure::Figure(double x, double y) :
    pos(x,y)
{
    vel = Point(6.0 - rand() % 13, 6.0 - rand() % 13);
    color = al_map_rgb(0, 0, 0);
}

Figure::Figure(Point pos_):
    pos(pos_)
{
    vel = Point(6.0 - rand() % 13, 6.0 - rand() % 13);
    color = al_map_rgb(0, 0, 0);
}

Figure::~Figure() {}

void Figure::setPos(Point pos_)
{
    pos = pos_;
}

void Figure::setVel(Point vel_)
{
    vel = vel_;
}

void Figure::setColor(ALLEGRO_COLOR color_)
{
    color = color_;
}

void Figure::Move()
{
    pos += vel;
};

void Figure::CollideWithBounds() // for symmetrical figures only
{
    double collisionDistance = getCollisionDistance();

    if (pos.x - collisionDistance < 0) {
        vel.x = -vel.x;
        pos.x = collisionDistance;
    }
    if (pos.x + collisionDistance > SCREEN_W) {
        vel.x = -vel.x;
        pos.x = SCREEN_W - collisionDistance;
    }
    if (pos.y - collisionDistance < 0) {
        vel.y = -vel.y;
        pos.y = collisionDistance;
    }
    if (pos.y + collisionDistance > SCREEN_H) {
        vel.y = -vel.y;
        pos.y = SCREEN_H - collisionDistance;
    }
}

void Figure::CollideWithFigure(Figure* other) {
    double collisionDistance = getCollisionDistance();
    double other_collisionDistance = other->getCollisionDistance();

    Point delta;
    delta = other->pos - pos;

    Point intersect;
	intersect.x = abs(delta.x) - (other_collisionDistance + collisionDistance);
	intersect.y = abs(delta.y) - (other_collisionDistance + collisionDistance);

	if (intersect.x < 0.0 && intersect.y < 0.0) { //collision detected
        Point temp_vel = vel;
		if (intersect.x > intersect.y) { //collision on x axis
            //push out of collision
			if (delta.x > 0.0) { 
				pos += Point(intersect.x, 0);
			}
			else {
				pos -= Point(intersect.x, 0);
			}

            //switch X velocity
            vel.x *= -1;
            other->vel.x *= -1;
		}
		else { //collision on y axis
            //push out of collision
			if (delta.y > 0.0) {
				pos += Point(0, delta.y);
			}
			else {
				pos -= Point(0, delta.y);
			}

            //switch Y velocity
            vel.y *= -1;
            other->vel.y *= -1;
		}
	}
}
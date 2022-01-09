#include "Point.h"

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

Point::Point(double x_, double y_)
{
	x = x_;
	y = y_;
}

Point::~Point(){}

Point Point::operator=(const Point p)
{
	x = p.x;
	y = p.y;
	return *this;
}

Point Point::operator+(Point p)
{
	return Point(x + p.x, y + p.y);
}

Point Point::operator-(Point p)
{
	return Point(x - p.x, y - p.y);
}


Point Point::operator+=(const Point p)
{
	x += p.x;
	y += p.y;
	return *this;
}

Point Point::operator-=(const Point p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}

Point Point::operator*(float d)
{
	return Point(this->x*d, this->y*d);
}

Point Point::operator*=(float d)
{
	x *= d;
	y *= d;
	return *this;
}

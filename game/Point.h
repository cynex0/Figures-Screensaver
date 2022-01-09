#pragma once
class Point {
public:
	double x;
	double y;

	Point();
	Point(double x_, double y_);
	~Point();

	Point operator=(Point p);
	Point operator+(Point p);
	Point operator-(Point p);
	Point operator+=(Point p);
	Point operator-=(Point p);
	Point operator*(float d);
	Point operator*=(float d);
};
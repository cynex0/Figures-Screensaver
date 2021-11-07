#include "Circle.h"
#include "Figure.h"
#include "AllegroApp.h"
#include "StringParser.h"

Circle::Circle():
    Figure()
{
    r_ = 0;
}

Circle::Circle(double x, double y, double r) :
    Figure(x, y),
    r_(r)
{}

Circle::~Circle() {};

void Circle::setR(double r) {
    r_ = r;
}

string Circle::ToString() {
    char buffer[150];
    int n = sprintf_s(buffer, "Circle: x=%f, y=%f, radius=%f", x_, y_, r_);
    return buffer;
}

void Circle::FromString(string s) {
    x_ = StringParser::valFromStr(s, "x=");
    y_ = StringParser::valFromStr(s, "y=");
    r_ = StringParser::valFromStr(s, "radius=");
}

double Circle::getCollisionDistance() {
    return r_;
}

void Circle::Draw()
{
    if (r_ != 0) {
        al_draw_filled_circle(x_, y_, r_, al_map_rgb(0, 255, 0));
    }
}
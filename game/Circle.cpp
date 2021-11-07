#include "Circle.h"
#include "Figure.h"
#include "AllegroApp.h"

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
    s += ','; //to indicate EOL
    string x = "", y = "", size = "";
    int pos = 0;
    while ((pos = s.find(',')) != std::string::npos) { // iterate with substrings divided by ','
        if (s.substr(0, pos).find('x') != std::string::npos) {
            x = s.substr(s.find("=") + 1, pos - s.find("x=") - 2); //get substring between 'x=' and ','
        }
        if (s.substr(0, pos).find('y') != std::string::npos) {
            y = s.substr(s.find("=") + 1, pos - s.find("y=") - 2);
        }

        if ((s.substr(0, pos).find("r") != std::string::npos) ||
            (s.substr(0, pos).find("radius") != std::string::npos))
        {
            size = s.substr(s.find("=") + 1, pos - s.find("=") - 1);
        }
        s.erase(0, pos + 1);
    }
    x_ = stod(x);
    y_ = stod(y);
    r_ = stod(size);
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
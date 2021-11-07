#include "Square.h"
#include "Figure.h"
#include "AllegroApp.h"
#include <iostream>


Square::Square() :
    Figure()
{
    a_ = 0;
}

Square::Square(double x, double y, double a) :
    Figure(x, y),
    a_(a)
{}
Square::~Square() {};

string Square::ToString() {
    char buffer[150];
    int n = sprintf_s(buffer, "Square: x=%f, y=%f, side=%f", x_, y_, a_);
    return buffer;
}

void Square::FromString(string s) {
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
        if (s.substr(0, pos).find("side") != std::string::npos)
        {
            size = s.substr(s.find("=") + 1, pos - s.find("=") - 1);
        }
        s.erase(0, pos + 1);
    }
    x_ = stod(x);
    y_ = stod(y);
    a_ = stod(size);
}

double Square::getCollisionDistance()
{
    return a_ / 2;
}

void Square::Draw()
{
    if (a_ != 0){
        double half = a_ / 2;
        al_draw_filled_rectangle(x_ - half, y_ - half,
            x_ + half, y_ + half, al_map_rgb(255, 0, 0));
    }
}
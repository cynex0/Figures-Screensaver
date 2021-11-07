#include "Square.h"
#include "Figure.h"
#include "AllegroApp.h"
#include "StringParser.h"
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
    x_ = StringParser::valFromStr(s, "x=");
    y_ = StringParser::valFromStr(s, "y=");
    a_ = StringParser::valFromStr(s, "side=");
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
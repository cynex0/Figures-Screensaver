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
    int n = sprintf_s(buffer, "Square: x=%f, y=%f, side=%f", pos.x, pos.y, a_);
    return buffer;
}

void Square::FromString(string s) {
    pos.x = StringParser::valFromStr(s, "x=");
    pos.y = StringParser::valFromStr(s, "y=");
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
        al_draw_filled_rectangle(pos.x - half, pos.y - half,
            pos.x + half, pos.y + half, al_map_rgb(255, 0, 0));
    }
}
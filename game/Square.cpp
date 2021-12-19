#include "Square.h"
#include "Figure.h"
#include "AllegroApp.h"
#include "StringParser.h"
#include <iostream>


Square::Square() :
    Figure()
{
    a_ = 0;
    half = 0;
    color = al_map_rgb(255, 0, 0);
}

Square::Square(double x, double y, double a) :
    Figure(x, y),
    a_(a)
{
    color = al_map_rgb(255, 0, 0);
    half = a_ / 2;
}
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
    half = a_ / 2;
}

double Square::getCollisionDistance()
{
    return a_ / 2;
}

void Square::Draw()
{
    if (a_ != 0){
        al_draw_filled_rectangle(pos.x - half, pos.y - half,
            pos.x + half, pos.y + half, color);
    }
}
#pragma once
#include "Figure.h"

class FigureFactory
{
public:
    static Figure* CreateRandomSquare();
    static Figure* CreateRandomCircle();
    static Figure* CreateFromString(string input);
};
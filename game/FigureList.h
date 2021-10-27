#pragma once
#include "constants.h"
#include "Figure.h"

class FigureList
{
private:
    Figure* figures[MAX_FIGS];
    int size_;

public:
    FigureList();
    virtual ~FigureList();

    void addFig(Figure* fig);
    void generateRandomFigures();
    void nextFrame();
    void drawAll();
};
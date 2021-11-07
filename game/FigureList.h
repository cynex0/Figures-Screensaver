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
    Figure* getFig(int i);
    int getSize();
    void generateRandomFigures();

    void moveAll();
    void drawAll();
};
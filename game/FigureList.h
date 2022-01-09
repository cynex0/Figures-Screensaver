#pragma once
#include "constants.h"
#include "Figure.h"
#include <vector>

class FigureList
{
private:
    std::vector<Figure*> figures;
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
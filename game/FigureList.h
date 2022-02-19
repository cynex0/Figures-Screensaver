#pragma once
#include "constants.h"
#include "Figure.h"
#include <vector>

class FigureList
{
private:
    std::vector<Figure*> figures;

public:  
    FigureList();
    FigureList(initializer_list<Figure*> init);
    virtual ~FigureList();

    void addFig(Figure* fig);
    Figure* getFig(int i);
    std::vector<Figure*> getList();
    int getSize();
    void generateRandomFigures();
    std::vector<int> countFigs();

    void moveAll();
    void drawAll();
};
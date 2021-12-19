#include "constants.h"
#include "FigureList.h"
#include "FigureFactory.h"
#include "AllegroApp.h"
#include <windows.h>
#include <iostream>

FigureList::FigureList() :
    size_(0)
{
}

FigureList::~FigureList() {}

Figure* FigureList::getFig(int i) {
    return figures.at(i);
}

int FigureList::getSize() {
    return size_;
}

void FigureList::addFig(Figure* fig) {
    figures.push_back(fig);
}

void FigureList::generateRandomFigures() {
    size_ = rand() % MAX_FIGS + 1;
    for (int i = 0; i < size_; ++i)
    {
        if (rand() % 2 == 0) {
            figures.push_back(FigureFactory::CreateRandomSquare());
        }
        else {
            figures.push_back(FigureFactory::CreateRandomCircle());
        }
    }
}

void FigureList::moveAll() 
{
    std::vector<Figure*>::iterator it = figures.begin();
    std::vector<Figure*>::iterator it2;

    for (it; it != figures.end(); it++) {
        Figure* fig = *it;
        for (it2 = it; it2 != figures.end(); it2++)
            fig->CollideWithFigure(*it2);
        fig->CollideWithBounds();
        fig->Move();
    }
}

void FigureList::drawAll()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (Figure* fig : figures)
        fig->Draw();
}


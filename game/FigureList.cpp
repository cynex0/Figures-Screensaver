#include "constants.h"
#include "FigureList.h"
#include "FigureFactory.h"
#include "AllegroApp.h"
#include <windows.h>
#include <iostream>

FigureList::FigureList() :
    size_(0)
{
    for (int i = 0; i < MAX_FIGS; ++i) {
        figures[i] = 0;
    }
}

FigureList::~FigureList() {
    for (int i = 0; i < size_; ++i)
    {
        delete figures[i];
        figures[i] = 0;
    }
}

Figure* FigureList::getFig(int i) {
    return figures[i];
}

int FigureList::getSize() {
    return size_;
}

void FigureList::addFig(Figure* fig) {
    if (size_ < MAX_FIGS) {
        figures[size_] = fig;
        size_++;
    }
}

void FigureList::generateRandomFigures() {
    size_ = rand() % MAX_FIGS + 1;
    for (int i = 0; i < size_; ++i)
    {
        if (rand() % 2 == 0) {
            figures[i] = FigureFactory::CreateRandomSquare();
        }
        else {
            figures[i] = FigureFactory::CreateRandomCircle();
        }
    }
}

void FigureList::moveAll() 
{
    for (int i = 0; i < size_; ++i)
    {
        figures[i]->Move();
        for (int j = i + 1; j < size_; ++j) {
            figures[i]->CollideWithFigure(figures[j]);
        }
        figures[i]->CollideWithBounds();
    }
}

void FigureList::drawAll()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (int i = 0; i < size_; ++i)
    {
        figures[i]->Draw();
    }
}


#include "constants.h"
#include "FigureList.h"
#include "FigureFactory.h"
#include "AllegroApp.h"
#include <algorithm>
#include <windows.h>
#include <iostream>

FigureList::FigureList() {}

FigureList::FigureList(initializer_list<Figure*> init) {
    for (Figure* fig : init) {
        figures.push_back(fig);
    }
}

FigureList::~FigureList() {}

Figure* FigureList::getFig(int i) {
    return figures.at(i);
}

std::vector<Figure*> FigureList::getList() {
    return figures;
}

int FigureList::getSize() {
    return figures.size();
}

void FigureList::addFig(Figure* fig) {
    figures.push_back(fig);
}

void FigureList::generateRandomFigures() {
    for (int i = 0; i < (rand() % MAX_FIGS + 1); ++i)
    {
        if (rand() % 2 == 0) {
            figures.push_back(FigureFactory::CreateRandomSquare());
        }
        else {
            figures.push_back(FigureFactory::CreateRandomCircle());
        }
    }
}

std::vector<int> FigureList::countFigs()
{
    int s1 = std::count_if(figures.begin(), figures.end(), [](Figure* f)
        { return (f->getPos().x >= SCREEN_W / 2) && (f->getPos().y <= SCREEN_H / 2); }); //top right

    int s2 = std::count_if(figures.begin(), figures.end(), [](Figure* f)
        { return (f->getPos().x < SCREEN_W / 2) && (f->getPos().y <= SCREEN_H / 2); }); //top left

    int s3 = std::count_if(figures.begin(), figures.end(), [](Figure* f)
        { return (f->getPos().x < SCREEN_W / 2) && (f->getPos().y > SCREEN_H / 2); }); //bottom left

    int s4 = std::count_if(figures.begin(), figures.end(), [](Figure* f)
        { return (f->getPos().x >= SCREEN_W / 2) && (f->getPos().y > SCREEN_H / 2); }); //bottom right

    return {s1, s2, s3, s4};
}

void FigureList::moveAll() 
{
    for (auto it = figures.begin(); it != figures.end(); it++) {
        Figure* fig = *it;
        for (auto it2 = it; it2 != figures.end(); it2++)
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


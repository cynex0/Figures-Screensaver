#include "AllegroApp.h"
#include "FigureList.h"


AllegroApp::AllegroApp() {
    srand(time(NULL));
    figureList.generateRandomFigures();
}

AllegroApp::~AllegroApp() {}

AllegroApp& AllegroApp::Instance() {
    static AllegroApp instance;
    return instance;
}

void AllegroApp::Fps()
{
    figureList.nextFrame();
}

void AllegroApp::Draw()
{
    figureList.drawAll();
}
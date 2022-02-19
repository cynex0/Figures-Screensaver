#include "AllegroApp.h"
#include "FigureList.h"
#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
#include "Point.h"
#include "FigureFactory.h"


AllegroApp::AllegroApp() {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        player = FigureFactory::CreateRandomSquare();
    }
    else {
        player = FigureFactory::CreateRandomCircle();
    }
    player->setColor(al_map_rgb(0, 0, 255));
    player->setVel(Point(0, 0));
    figureList.addFig(player);
    figureList.generateRandomFigures();
}

AllegroApp::~AllegroApp() {}

AllegroApp& AllegroApp::Instance() {
    static AllegroApp instance;
    return instance;
}

void AllegroApp::Fps()
{
    newVel = Point(0, 0);
    if (IsPressed(ALLEGRO_KEY_UP))
        newVel += Point(0, -2);
    else if (IsPressed(ALLEGRO_KEY_DOWN))
        newVel += Point(0, 2);

    if (IsPressed(ALLEGRO_KEY_LEFT))
        newVel += Point(-2, 0);
    else if (IsPressed(ALLEGRO_KEY_RIGHT))
        newVel += Point(2, 0);
    
    figureList.getFig(0)->setVel(newVel);
    figureList.moveAll();
}

void AllegroApp::Draw()
{
    figureList.drawAll();
}

void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT& keyboard)
{
    switch (keyboard.keycode) {
    case ALLEGRO_KEY_ESCAPE:
    {
        Exit();
        break;
    }

    case ALLEGRO_KEY_I:
    {
        string input = "";
        getline(cin, input);
        figureList.addFig(FigureFactory::CreateFromString(input));
        break;
    }

    case ALLEGRO_KEY_O:
    {
        for (Figure* fig : figureList.getList()) {
            std::cout << fig->ToString() << std::endl;
        }
        break;
    }
    case ALLEGRO_KEY_S:
    {
        std::vector<int> quadrants;
        
        quadrants = figureList.countFigs();          
        
        std::cout << "I: " << quadrants[0] << std::endl;
        std::cout << "II: " << quadrants[1] << std::endl;
        std::cout << "III: " << quadrants[2] << std::endl;
        std::cout << "VI: " << quadrants[3] << std::endl;
        break;
    }
    }
};
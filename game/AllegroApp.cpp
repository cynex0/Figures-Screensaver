#include "AllegroApp.h"
#include "FigureList.h"
#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
#include "FigureFactory.h"


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
    figureList.moveAll();
}

void AllegroApp::Draw()
{
    figureList.drawAll();
}

void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT & keyboard)
{
    if (keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    {
        Exit();
    }

    else if (keyboard.keycode == ALLEGRO_KEY_I) {
        string input = "";
        getline(cin, input);
        figureList.addFig(FigureFactory::CreateFromString(input));
    }

    else if (keyboard.keycode == ALLEGRO_KEY_O) {
        for (int i = 0; i < figureList.getSize(); ++i)
        {
            cout << figureList.getFig(i)->ToString() << endl;
        }
    }
}

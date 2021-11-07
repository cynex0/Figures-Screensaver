#include "AllegroApp.h"
#include "FigureList.h"
#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"


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

        Figure* f = 0;
        const string& figureType = input.substr(0, input.find(':'));
        const string& values = input.substr(input.find(':') + 1);

        if (figureType == "Square") {
            f = new Square();
        }
        else if (figureType == "Circle") {
            f = new Circle();
        }

        input.erase(0, input.find(':') + 1);
        if (f != 0) {
            f->FromString(values);
        }

        figureList.addFig(f);
    }

    else if (keyboard.keycode == ALLEGRO_KEY_O) {
        for (int i = 0; i < figureList.getSize(); ++i)
        {
            cout << figureList.getFig(i)->ToString() << endl;
        }
    }
}

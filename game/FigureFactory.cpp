#include "FigureFactory.h"
#include "constants.h"
#include "Circle.h"
#include "Square.h"
#include "Figure.h"
#include <iostream>

Figure* FigureFactory::CreateRandomSquare() {
    return new Square(rand() % SCREEN_W, rand() % SCREEN_H, (rand() % MAX_FIG_SIZE) + 15);
}

Figure* FigureFactory::CreateRandomCircle() {
    return new Circle(rand() % SCREEN_W, rand() % SCREEN_H, (rand() % MAX_FIG_SIZE) + 15);
}

Figure* FigureFactory::CreateFromString(string input) {
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

    return f;
}

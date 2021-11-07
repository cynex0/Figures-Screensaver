#include "FigureFactory.h"
#include "constants.h"
#include "Circle.h"
#include "Square.h"
#include "Figure.h"
#include <iostream>

Figure* FigureFactory::CreateRandomSquare() {
    return new Square(rand() % SCREEN_W, rand() % SCREEN_H, rand() % MAX_FIG_SIZE);
}

Figure* FigureFactory::CreateRandomCircle() {
    return new Circle(rand() % SCREEN_W, rand() % SCREEN_H, rand() % MAX_FIG_SIZE);
}

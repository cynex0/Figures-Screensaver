#include <iostream>
#include "AllegroUtil.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 450;
const int MAX_FIGS = 10;
const int MAX_FIG_SIZE = 75;

class Figure
{
protected:
    double x_;
    double y_;
    double dx_;
    double dy_;
    double center_to_edge;

public:
    Figure(double x, double y):
        x_(x),
        y_(y)
    {
        dx_ = 10.0 - rand() % 21;
        dy_ = 10.0 - rand() % 21;
    }

    virtual ~Figure() {};

    virtual void Draw() {}

    virtual void Move()
    {
        x_ += dx_;
        y_ += dy_;
    };

    virtual void CollideWithBounds() // for symmetrical figures only
    {
        if (x_ - center_to_edge <= 0) {
            dx_ = -dx_;
            x_ = center_to_edge;
        }
        if (x_ + center_to_edge >= SCREEN_W) {
            dx_ = -dx_;
            x_ = SCREEN_W - center_to_edge;
        }
        if (y_ - center_to_edge <= 0) {
            dy_ = -dy_;
            y_ = center_to_edge;
        }
        if (y_ + center_to_edge >= SCREEN_H) {
            dy_ = -dy_;
            y_ = SCREEN_H - center_to_edge;
        }
    }
};


class Square: public Figure
{
protected:
    double a_;
    double half;
public:
    Square(double x, double y, double a) :
        Figure( x, y ),
        a_( a )
    {
        half = a_ / 2;
        center_to_edge = half;
    }

    virtual void Draw()
    {
        al_draw_filled_rectangle(x_ - half, y_ - half,
            x_ + half, y_ + half, al_map_rgb(255, 0, 0));
    }
};

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle(double x, double y, double r): 
        Figure( x, y ),
        r_( r )
    {
        center_to_edge = r_;
    }

    virtual void Draw()
    {
        al_draw_filled_circle(x_, y_, r_, al_map_rgb(0, 255, 0));
    }
};

class FigureList 
{
private:
    Figure* figures[MAX_FIGS];
    unsigned int size_;

public:
    FigureList() :
        size_( 0 )
    {
        for (int i = 0; i < MAX_FIGS; ++i) {
            figures[i] = 0;
        }
    }

    ~FigureList() {
        for (int i = 0; i < size_; ++i)
        {
            delete figures[i];
            figures[i] = 0;
        }
    }

    void addFig(Figure *fig) {
        if (size_ < MAX_FIGS){
            figures[size_] = fig;
            size_++;
        }
    }

    void generateRandomFigures() {
        double rand_x, rand_y, rand_size;
        size_ = rand() % MAX_FIGS + 1;       
        for (int i = 0; i < size_; ++i)
        {
            rand_x = rand() % SCREEN_W;
            rand_y = rand() % SCREEN_H;
            rand_size = rand() % MAX_FIG_SIZE;
            if (rand() % 2 == 0) {
                figures[i] = new Square(rand_x, rand_y, rand_size);
            }
            else {
                figures[i] = new Circle(rand_x, rand_y, rand_size);
            }
        }
    }

    void nextFrame() 
    {
        for (int i = 0; i < size_; ++i)
        {
            figures[i]->Move();
            figures[i]->CollideWithBounds();
        }
    }

    void drawAll() 
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        for (int i = 0; i < size_; ++i)
        {
            figures[i]->Draw();
        }
    }
};

FigureList figureList;
void fps()
{
    figureList.nextFrame();
}

void draw()
{
    figureList.drawAll();
}

int main(int argc, char** argv)
{
    srand(time(0));
    if (!InitAllegro(SCREEN_W, SCREEN_H, FPS))
    {
        DestroyAllegro();
        return 1;
    }

    //add figures manually
    // 
    //Square *square = new Square(100,100,50);
    //Circle *circle = new Circle(200,250,40);
    //figureList.addFig(square);
    //figureList.addFig(circle);

    figureList.generateRandomFigures();
    RunAllegro(&fps, &draw);
    DestroyAllegro();

    // cin.get();
    return 0;
}

#pragma once
#include "FigureList.h"
#include "AllegroBase.hpp"

class AllegroApp : public AllegroBase
{
private:
    AllegroApp();
    AllegroApp(const AllegroApp&) = delete;
    AllegroApp& operator=(const AllegroApp&) = delete;
    virtual ~AllegroApp();
    FigureList figureList;
    Figure* player;
    Point newVel;

public:
    static AllegroApp& Instance();

    virtual void Fps();
    virtual void Draw();
    virtual void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT& keyboard);
};

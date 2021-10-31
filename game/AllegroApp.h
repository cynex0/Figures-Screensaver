#pragma once
#include "FigureList.h"
#include "AllegroBase.hpp"

class AllegroApp : public AllegroBase
{
private:
    AllegroApp();
    virtual ~AllegroApp();
    FigureList figureList;

public:
    static AllegroApp& Instance();

    virtual void Fps();
    virtual void Draw();
};

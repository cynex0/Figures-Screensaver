#include <iostream>
#include "constants.h"
#include "FigureList.h"
#include "AllegroApp.h"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

FigureList figureList;
int main(int argc, char** argv)
{
    if (!AllegroApp::Instance().Init(SCREEN_W, SCREEN_H, FPS))
    {
        AllegroApp::Instance().Destroy();
        return 1;
    }

    AllegroApp::Instance().Run();
    return 0;
}

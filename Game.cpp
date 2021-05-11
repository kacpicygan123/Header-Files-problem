#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "Game.h"

void Game::initGame() {
    isRunning = true;
    while (isRunning)
    {
        eventSystem.trackEvents();
    }
}


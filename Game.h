#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <list>
#include "Events.h"

class Game {
private:
    EventSystem eventSystem;
public:
    void initGame();
};
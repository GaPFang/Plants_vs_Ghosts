#include "Variables.h"

PlantType gPlantType = PLANT_TOTAL;
DisplayType gDisplayType = MENU;
Coin coin;
bool usingShovel = false;
int Price[5] = {50, 50, 50, 100, 150};
Uint32 CDtime[5] = {};
bool existingEnemy[5] = {false};
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
SDL_Window* Window = SDL_CreateWindow ("Plants vs Ghosts", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


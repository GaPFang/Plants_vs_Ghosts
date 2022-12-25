#include "Shovel.h"

Shovel::Shovel(){}

Shovel::~Shovel(){}

void Shovel::handleEvent (const SDL_Event& eventListener) {
    if (eventListener.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        bool inside = true;
        if (x < gPos.x) inside = false;
        else if (x > gPos.x + width) inside = false;
        else if (y < gPos.y) inside = false;
        else if (y > gPos.y + height) inside = false;
        if (inside) {
            gPlantType = PLANT_TOTAL;
            if (!usingShovel) usingShovel = true;
            else usingShovel = false;
        }
    }
}

double Shovel::getWidth() {
    return width;
}

double Shovel::getHeight() {
    return height;
}

SDL_Point Shovel::getGPos() {
    return gPos;
}

SDL_Point Shovel::getMPos() {
    return mPos;
}

void Shovel::followingMouse() {
    if (usingShovel) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        mPos.x = x - width / 2;
        mPos.y = y - height / 2;
    }
}

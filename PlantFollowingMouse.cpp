#include "PlantFollowingMouse.h"

PlantFollowingMouse::PlantFollowingMouse(){}

PlantFollowingMouse::PlantFollowingMouse(const PlantFollowingMouse & p) {}

PlantFollowingMouse::~PlantFollowingMouse(){}

void PlantFollowingMouse::followingMouse() {
    int x, y;
    SDL_GetMouseState( &x, &y );
    pos.x = x - width / 2;
    pos.y = y - height / 2;
}

PlantType PlantFollowingMouse::getPlantType() {
    return plantType;
}

double PlantFollowingMouse::getWidth(){
    return width;
}

double PlantFollowingMouse::getHeight() {
    return height;
}

SDL_Point PlantFollowingMouse::getPos() {
    return pos;
}

const double PlantFollowingMouse::width = 90, PlantFollowingMouse::height = 90;

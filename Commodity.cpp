#include "Commodity.h"

Commodity::Commodity(){}

Commodity::~Commodity(){}

void Commodity::handleEvent(const SDL_Event& eventListener) {
    if (eventListener.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        bool inside = true;
        if (x < mPos.x) inside = false;
        else if (x > mPos.x + width) inside = false;
        else if (y < mPos.y) inside = false;
        else if (y > mPos.y + height) inside = false;
        if (inside && ready) {
            usingShovel = false;
            if (gPlantType != mPlantType) {
                gPlantType = mPlantType;
            } else {
                gPlantType = PLANT_TOTAL;
            }
        }
    }
}

int Commodity::getCommodityID() {return ID;}

double Commodity::getWidth() {
    return width;
}

double Commodity::getHeight() {
    return height;
}

SDL_Point Commodity::getGPos() {
    return gPos;
}

SDL_Point Commodity::getMPos() {
    return mPos;
}

bool Commodity::getReady() {
    return ready;
}

void Commodity::setReady(int i) {
    if (SDL_GetTicks() - CDtime[i] >= CDinterval && coin.getCurrentCoin() >= Price[mPlantType]) {
        ready = true;
        setAlpha(255);
    } else {
        ready = false;
        setAlpha(100);
    }
}

void Commodity::setCDinterval(Uint32 interval, int i) {
    CDinterval = interval;
    CDtime[i] = SDL_GetTicks() + interval;
}

void Commodity::setPosX(double x) {
    mPos.x = x;
}

void Commodity::setPosY(double y) {
    mPos.y = y;
}

void Commodity::setMPlantType(PlantType t) {
    mPlantType = t;
}

int Commodity::ID = 0;
const SDL_Point Commodity::gPos = {30, 150};
const double Commodity::width = 90, Commodity::height = 90;
//bool Commodity::isSelling = false;




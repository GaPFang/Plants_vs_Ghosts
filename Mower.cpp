#include "Mower.h"

Mower::Mower() {}

Mower::~Mower(){}

double Mower::getWidth() {
    return width;
}

double Mower::getHeight() {
    return height;
}

SDL_Point Mower::getPos() {
    return mPos;
}

void Mower::setRow(int r) {
    row = r;
}

void Mower::setPos() {
    mPos.x = gPos.x;
    mPos.y = gPos.y + height * row + (height - width) / 2;
}

void Mower::move() {
    mPos.x += M_SPD;
}

void Mower::setMoving(bool b) {
    moving = true;
}

bool Mower::getMoving() {
    return moving;
}

const double Mower::width = 100, Mower::height = (double)520 / 5;
const SDL_Point Mower::gPos = {340, 200};
const int Mower::M_SPD = 8;

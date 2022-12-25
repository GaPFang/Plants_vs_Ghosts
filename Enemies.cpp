#include "Enemies.h"

Enemies::Enemies(){}

Enemies::~Enemies(){}

double Enemies::getWidth() {
    return width;
}

double Enemies::getHeight() {
    return height;
}

SDL_Point Enemies::getPos() {
    return mPos;
}

bool Enemies::getMoving() {
    return moving;
}

void Enemies::setMoving(bool b) {
    moving = b;
}

void Enemies::setRow(int r) {
    row = r;
}

void Enemies::setID(int id) {
    ID = id;
}

void Enemies::setPos() {
    mPos.x = SCREEN_WIDTH;
    mPos.y = gPos.y + height * row + (height - width) / 2;
}

void Enemies::move() {
    mPos.x -= M_SPD;
}

void Enemies::HPdamaged(int damage) {HP -= damage;}

const int Enemies::M_SPD = 1;
const double Enemies::width = (double)740 / 9, Enemies::height = (double)520 / 5;
const SDL_Point Enemies::gPos = {436, 200};


#include "Plants.h"

Plants::Plants() {}

Plants::~Plants(){}

double Plants::getWidth() {
    return width;
}

double Plants::getHeight() {
    return height;
}

SDL_Point Plants::getPos() {
    return mPos;
}

void Plants::setColumn(int c) {
    column = c;
}

void Plants::setRow(int r) {
    row = r;
}

void Plants::setPos() {
    mPos.x = gPos.x + width * column;
    mPos.y = gPos.y + height * row + (height - width) / 2;
}

void Plants::HPdamaged (int damage) {HP -= damage;}

int Plants::getHP(){
    return HP;
}

int Plants::getATK(){
    return ATK;
}
const double Plants::width = (double)740 / 9, Plants::height = (double)520 / 5;
const SDL_Point Plants::gPos = {436, 200};

#include "PeaBullet.h"

PeaBullet::PeaBullet(){}

void PeaBullet::setStartPosX(double x) {
    startPos.x = x;
}

void PeaBullet::setStartPosY(double y) {
    startPos.y = y;
}

void PeaBullet::setNowPos() {
    nowPos = startPos;
}

void PeaBullet::setRow(int r) {
    row = r;
}

SDL_Point PeaBullet::getNowPos() {
    return nowPos;
}

int PeaBullet::getRow() {
    return row;
}

void PeaBullet::setMoving(bool b) {
    moving = b;
}

double PeaBullet::getWidth() {
    return width;
}

double PeaBullet::getHeight() {
    return height;
}

void PeaBullet::setReady(bool b) {
    ready = b;
}

bool PeaBullet::getMoving() {
    return moving;
}

bool PeaBullet::getReady() {
    return ready;
}

void PeaBullet::move() {
    nowPos.x += M_SPD;
}

const double PeaBullet::width = 30, PeaBullet::height = 30;
int PeaBullet::ATK = 20;
const int PeaBullet::M_SPD = 4;

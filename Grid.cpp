#include "Grid.h"

Grid::Grid(){}

Grid::~Grid (){}

double Grid::getWidth() {
    return width;
}

double Grid::getHeight() {
    return height;
}

PlantType Grid::getMPlantType() {
    return mPlantType;
}

SDL_Point Grid::getPos() {
    return mPos;
}

void Grid::setColumn(int c) {
    column = c;
}

void Grid::setRow(int r) {
    row = r;
}

void Grid::setPos() {
    mPos.x = gPos.x + width * column;
    mPos.y = gPos.y + height * row;
}

void Grid::handleEvent(const SDL_Event& eventListener) {
    if (eventListener.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        bool inside = true;
        if (x < mPos.x) inside = false;
        else if (x > mPos.x + width) inside = false;
        else if (y < mPos.y) inside = false;
        else if (y > mPos.y + height) inside = false;
        if (inside) {
            if (gPlantType != PLANT_TOTAL && mPlantType == PLANT_TOTAL) {
                CDtime[gPlantType] = SDL_GetTicks();
                coin.deductCoin(Price[gPlantType]);
                mPlantType = gPlantType;
                gPlantType = PLANT_TOTAL;
                chunk = Mix_LoadWAV( "sound/plantingChunk.wav" );
                Mix_PlayChannel( -1, chunk, 0 );
            } else if (usingShovel && mPlantType != PLANT_TOTAL) {
                //usingShovel = false;
                mPlantType = PLANT_TOTAL;
                chunk = Mix_LoadWAV( "sound/shovel.wav" );;
                Mix_PlayChannel( -1, chunk, 0 );
            }
        }
    }
}
void Grid::resetCollide(){}
int Grid::getmPosX(){
    return mPos.x;
}

int Grid::getmPosY(){
    return mPos.y;
}

int Grid::getRow(){
    return row;
}

int Grid::getColumn(){
    return column;
}

const double Grid::width = (double)740 / 9, Grid::height = (double)520 / 5;
const SDL_Point Grid::gPos = {436, 200};
//Mix_Chunk *Grid::plantingChunk = Mix_LoadWAV( "sound/scratch.wav" );

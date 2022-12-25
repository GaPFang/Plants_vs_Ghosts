#ifndef _GRID_H
#define _GRID_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "Enum.h"
#include "Coin.h"

extern PlantType gPlantType;
extern Uint32 CDtime[5];
extern Coin coin;
extern int Price[5];
extern bool usingShovel;

class Grid {
    private:
        static const double width, height;
        static const SDL_Point gPos;
        //static Mix_Chunk *plantingChunk;
        int column, row;
        SDL_Point mPos;
        bool planted = false;
        bool collided = false;
        PlantType mPlantType = PLANT_TOTAL;
        Mix_Chunk *chunk = NULL;
    public:
        Grid();
        ~Grid();
        double getWidth();
        double getHeight();
        PlantType getMPlantType();
        SDL_Point getPos();
        void setColumn(int);
        void setRow(int);
        void setPos();
        int getRow();
        int getColumn();
        int getmPosX();
        int getmPosY();
        void handleEvent (const SDL_Event&);
        void setMPlantType(PlantType t);
        void collide();
        void resetCollide();
};

#endif // _GRID_H

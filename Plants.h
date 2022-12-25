#ifndef _PLANTS_H
#define _PLANTS_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

#include "Animation.h"

class Plants: public Animation{
    protected:
        static const double width, height;
        static const SDL_Point gPos;
        SDL_Point mPos;
        int HP = 100;
        const int ATK = 10;
        const int price = 100;
        int column, row;
    public:
        Plants();
        ~Plants();
        double getWidth();
        double getHeight();
        SDL_Point getPos();
        void setColumn(int);
        void setRow(int);
        void setPos();
        void HPdamaged(int);
        int getHP();
        int getATK();
};

#endif // _PLANTS_H

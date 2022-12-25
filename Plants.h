#ifndef _PLANTS_H
#define _PLANTS_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

#include "Animation.h"
#include "Enum.h"

class Plants: public Animation{
    protected:
        static const double width, height;
        static const SDL_Point gPos;
        SDL_Point mPos;
        double HP = 100;
        double ATK = 10;
        const int price = 100;
        int column, row;
        AnimationType animationType = RESTING;
    public:
        Plants();
        ~Plants();
        double getWidth();
        double getHeight();
        SDL_Point getPos();
        void setColumn(int);
        void setRow(int);
        void setPos();
        void setHP(double);
        void setATK(double);
        void HPdamaged(double);
        double getHP();
        double getATK();
};

#endif // _PLANTS_H

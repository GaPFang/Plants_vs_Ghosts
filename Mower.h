#ifndef _MOWER_H
#define _MOWER_H

#include "LTexture.h"

class Mower: public LTexture {
    protected:
        static const double width, height;
        static const SDL_Point gPos;
        static const int M_SPD;
        SDL_Point mPos;
        int row;
        bool moving = false;
    public:
        Mower();
        ~Mower();
        double getWidth();
        double getHeight();
        SDL_Point getPos();
        void setRow(int);
        void setPos();
        void move();
        void setMoving(bool);
        bool getMoving();
};

#endif // _MOWER_H

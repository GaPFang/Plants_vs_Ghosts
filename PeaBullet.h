#ifndef _PEA_BULLET_H
#define _PEA_BULLET_H

#include <stdio.h>
#include <string>
#include "SDL.h"

#include "Animation.h"

class PeaBullet: public Animation{
    private:
        static const double width, height;
        static int ATK;
        static const int M_SPD;
        SDL_Point startPos;
        SDL_Point nowPos;
        int row;
        bool moving = false;
        bool ready = 1;
    public:
        PeaBullet();
        int getATK(){ return ATK; }
        void setStartPosX(double);
        void setStartPosY(double);
        void setNowPos();
        void setRow(int);
        void setMoving(bool);
        void setReady(bool);
        SDL_Point getNowPos();
        double getWidth();
        double getHeight();
        int getRow();
        bool getMoving();
        bool getReady();
        void move();
        bool checkCollision();
};

#endif // _PEA_BULLET_H

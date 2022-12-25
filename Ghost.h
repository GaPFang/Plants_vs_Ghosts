#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include <iostream>
#include "Enemies.h"
#include "Animation.h"

class Ghost : public Enemies{
    public:
        Ghost();
        ~Ghost();
        void timeCount();
        //void setNum();
        Animation ghostAnimation;
        static int Numbers;
        bool collided = false;
        int iTick = 0;

    private:
        int HP = 100;
        int ATK = 5;
        bool nutInvulnerable = false;


};

#endif // GHOST_H_INCLUDED

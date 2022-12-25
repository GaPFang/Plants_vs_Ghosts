#ifndef _SHOVEL_H
#define _SHOVEL_H

#include "LTexture.h"
#include "Enum.h"

extern bool usingShovel;

extern const int SCREEN_WIDTH;
extern PlantType gPlantType;

class Shovel: public LTexture{
    private:
        const double width = 80, height = 80;
        const SDL_Point gPos{SCREEN_WIDTH - 180, 0};
        SDL_Point mPos;
    public:
        Shovel();
        ~Shovel();
        void handleEvent (const SDL_Event&);
        double getWidth();
        double getHeight();
        SDL_Point getGPos();
        SDL_Point getMPos();
        void followingMouse();
};

#endif // _SHOVEL_H

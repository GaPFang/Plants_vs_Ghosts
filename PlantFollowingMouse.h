#ifndef _PLANTFOLLOWINGMOUSE_H
#define _PLANTFOLLOWINGMOUSE_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

#include "LTexture.h"
#include "Enum.h"

extern SDL_Window* Window;

class PlantFollowingMouse: public LTexture {
    private:
        SDL_Point pos;
        PlantType plantType;
        static const double width, height;
    public:
        PlantFollowingMouse();
        PlantFollowingMouse(const PlantFollowingMouse &);
        ~PlantFollowingMouse();
        void followingMouse();
        PlantType getPlantType();
        double getWidth();
        double getHeight();
        SDL_Point getPos();
};

#endif // _PLANTFOLLOWINGMOUSE_H

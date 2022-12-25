#ifndef _COMMODITY_H
#define _COMMODITY_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

#include "Coin.h"
#include "Enum.h"

extern bool usingShovel;
extern PlantType gPlantType;
extern Uint32 CDtime[5];
extern Coin coin;
extern int Price[5];

class Commodity: public LTexture{
    private:
        static int ID;
        static const SDL_Point gPos;
        static const double width, height;
        const int price = 50;
        PlantType mPlantType;
        SDL_Point mPos;
        const LTexture plantTexure;
        Uint32 CDinterval;
        bool ready;
    public:
        Commodity();
        Commodity (PlantType, int);
        ~Commodity();
        void handleEvent (const SDL_Event&);
        int getCommodityID();
        double getWidth();
        double getHeight();
        SDL_Point getGPos();
        SDL_Point getMPos();
        bool getReady();
        void setReady(int i);
        void setCDinterval(Uint32, int i);
        void setPosX(double);
        void setPosY(double);
        void setMPlantType(PlantType t);
};


#endif // _COMMODITY_H

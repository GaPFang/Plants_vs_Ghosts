#ifndef COIN_H_INCLUDED
#define COIN_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
#include "SDL2/SDL_ttf.h"

#include "LTexture.h"



class Coin: public LTexture{
    public:
        void render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer, SDL_Texture* mTexture);
        bool loadMedia(std::string, SDL_Renderer*);
        bool init();
        void print(SDL_Renderer* gameRenderer);
        void deductCoin(int price);
        void coinCountUp();
        //void setiTick(Uint32 tick);
        int getCurrentCoin();
        void setCurrentCoin();

    private:
        Uint32 iTick = SDL_GetTicks();
        bool loadFromRenderedText( std::string textureText, SDL_Renderer* gRenderer, SDL_Color textColor = {1, 1, 1} );
        bool pauseTickDefined = false;
        bool gameStarted = false;
        Uint32 pauseTick = 50;
        static int currentCoin;
        Uint32 coinInterval = 7000;
        SDL_Rect coinRect;
        SDL_Rect* coinPos = &coinRect;
        TTF_Font *gFont = NULL;
};


#endif // COIN_H_INCLUDED

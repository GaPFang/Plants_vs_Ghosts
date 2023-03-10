#ifndef _GAME_H
#define _GAME_H

#include <ctime>
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

//#include "LTexture.h"
#include "Grid.h"
#include "Commodity.h"
#include "PlantFollowingMouse.h"
#include "Pea.h"
#include "Nut.h"
#include "PeaBullet.h"
#include "WatermelonGenerator.h"
#include "Girl.h"
#include "Ghost.h"
#include "Mower.h"
#include "Button.h"
#include "Shovel.h"
#include "Coin.h"
#include "Progress.h"
#include "Sunflower.h"

extern bool existingEnemy[5];

class Game{
    private:
        SDL_Renderer* gameRenderer = NULL;
        LTexture menuBackgroundTexture;
        LTexture levelSelectionBackgroundTexture;
        LTexture mainGameBackgroundTexture;
        LTexture pauseBackgroundTexture;
        PlantFollowingMouse plantFollowingMouse[5];
        Grid grid[5][9];
        Sunflower sunflower[5][9];
        Pea pea[5][9];
        Nut nut[5][9];
        PeaBullet watermelon[5][9];
        WatermelonGenerator watermelonGeneratorFront[5][9];
        WatermelonGenerator watermelonGeneratorBack[5][9];
        Girl girl[5][9];
        Mower mower[5];
        Ghost ghost[5][20];
        Commodity commodity[5];
        PeaBullet peaBullet[5][9][2];
        Button playButton;
        Button level[5];
        Button pauseButton;
        Button resumeButton, replayButton, exitButton;
        Progress progressBar;
        Progress progressBackground;
        Mix_Music *menuMusic = NULL;
        Mix_Music *mainGameMusic = NULL;
        Shovel shovel;
        Coin coin;
        int iTick;
        int eSequence[100] = {1,3,1,2,3,4,0,1,1,1,4,3,0,2,0,0,4,4,2,3,1,3,2,1,3,2,0,3,3,2,2,4,2,2,2,4,4,4,2,3,0,1,3,2,3,0,4,4,2,1,2,1,0,0,3,4,1,0,2,3,2,0,1,4,4,4,3,1,4,3,1,3,4,2,0,2,0,4,2,1,1,0,4,1,3,3,1,4,0,0,1,3,0,4,2,0,0,3,0,1};
        int eNum[5] = {0};
        int killedeNum[5] = {0};
        int count = 0;
        time_t num;
    public:
        Game();
        void init();
        void loadMedia();
        void initRenderPresent();
        void plantRenderPresent();
        void eventPrepare(const SDL_Event& eventListener);
        void autoPrepare();
        void renderPresent();
        void clearRender();
        void close();
        bool checkCollision(Enemies &enemy, int i, int j);
        void checkCollision(Enemies &enemy, PeaBullet &peaBullet, PlantType plantType);
        void checkCollision(Enemies &enemy, Mower &mower);
        int checkEnding();
};

#endif // _GAME_H

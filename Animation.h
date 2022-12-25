#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include "SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>

#include "LTexture.h"
#include "Enum.h"

extern DisplayType gDisplayType;

class Animation: public LTexture{
	public:
		Animation();
		//Animation(SDL_Renderer* renderer);
		~Animation();
        //bool loadMedia(std::string src, Animation &gSpriteSheetTexture);

        //int plt = 0;
        //int enmy = 1;
        //int ghost = 2;

		void animationLoadFromFile(std::string src, SDL_Renderer *gRenderer);
		void animationRender( int x, int y, SDL_Renderer *currentRenderer, SDL_Rect* clip = NULL);
		//void animationLoadFromFile(std::string path, AnimationType t);

		int getWidth();
		int getHeight();

		void setAlpha(Uint8);

		//SDL_Texture* getmTexture();
        //void resetmTexture();
        SDL_Rect* getCurrentClip();

        void move();
        //void attack(int code, Animation &gSpriteSheetTexture);
        //void die(int code, Animation &gSpriteSheetTexture);
        //void damaged(int code, Animation &gSpriteSheetTexture);

        AnimationType getAnimationType();
        void setAnimationType(AnimationType t);

        int getFrame();

        void free();
        void stop();
	protected:
	    static const int ANIMATION_FRAMES = 16;
        double movementInterval[ANIMATIONTYPE_TOTAL] = {16, 40, 16};  // in double digit scale
        double animationSpeed[ANIMATIONTYPE_TOTAL] = {1, 3, 3}; // in single digit scale
        int frame = 0;
        //bool start = false;
        AnimationType animationType = MOVING;
        SDL_Texture* gSpriteSheetTexture[ANIMATIONTYPE_TOTAL] = {NULL};
        SDL_Rect gSpriteClips[ANIMATION_FRAMES];
};

#endif // ANIMATION_H_INCLUDED

#include "Progress.h"
#include <iostream>

extern DisplayType gDisplayType;

void Progress::render( int x, int y, SDL_Renderer* currentRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
	SDL_Rect renderQuad = { x, y, 0, 0 };
	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx( currentRenderer, getmTexture(), NULL, &renderQuad, angle, center, flip );
}

void Progress::progressBarInit(){
    progressClip.w = 0;
    progressClip.h = 40;
}

void Progress::setGameLength(Uint32 length){
    gameLength = length;
}

void Progress::setTicksAfterStart(){
    if(gDisplayType == MENU){
        ticksAfterStart = SDL_GetTicks();
    } else if(gDisplayType == PAUSE){
        std::cout << "Paused!" << std::endl;
        if(pauseTickDefined == false){
            pauseTickDefined = true;
            pauseTick = SDL_GetTicks();
            std::cout << "Pause tick acquired!" << std::endl;
        }
    } else if(gDisplayType == MAINGAME && pauseTickDefined == true){
        pauseTickDefined = false;
        ticksAfterStart += SDL_GetTicks() - pauseTick;
        std::cout << "New tickAfterStart = " << ticksAfterStart << std::endl;
    } else if(gameStarted == false && gDisplayType == MAINGAME){
        gameStarted = true;
        ticksAfterStart = SDL_GetTicks();
    }

}

void Progress::setProgress(){
    if(gDisplayType == MENU){
        progressClip.w = 0;
    } else if(gDisplayType == MAINGAME){
        if(progressClip.w < 320 && gDisplayType == MAINGAME){
            progressClip.w = 320 * double((SDL_GetTicks() - ticksAfterStart)) / double(gameLength);
        }
    }

}

void Progress::progressBackgroundInit(){
    progressClip.x = 0;
    progressClip.y = 0;
    progressClip.w = 330;
    progressClip.h = 50;
}

Progress::Progress(){}
Progress::~Progress(){}



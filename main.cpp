#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

#include "Game.h"
#include "SDL2/SDL_mixer.h"

int main(int argc, char *argv[]){
    Game game;
	game.init();
	game.loadMedia();
    SDL_Event eventListener;
    //Mix_Chunk *plantingChunk = Mix_LoadWAV( "sound/scratch.wav" );
    bool quit = false;
    while( !quit )
    {
        while( SDL_PollEvent( &eventListener ) != 0 )
        {
            if( eventListener.type == SDL_QUIT )
            {
                quit = true;
            }
            game.eventPrepare(eventListener);

        }
        game.autoPrepare();
        game.renderPresent();
    }
    game.close();
	return 0;
}

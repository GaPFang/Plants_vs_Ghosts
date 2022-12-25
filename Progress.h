#ifndef PROGRESS_H_INCLUDED
#define PROGRESS_H_INCLUDED

#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "Animation.h"

class Progress : public Animation{
    private:
        Uint32 gameLength = 0;  //has to be set to a number in ms when the game starts
        Uint32 ticksAfterStart = 0;
        Uint32 pauseTick = 0;
        bool pauseTickDefined = false;
        bool gameStarted = false;

    public:
        void render( int x, int y, SDL_Renderer*, SDL_Rect* clip, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void setGameLength(Uint32 length);
        void setProgress();
        void progressBarInit();
        void progressBackgroundInit();
        void setTicksAfterStart();
        SDL_Rect progressClip;
        SDL_Rect* currentProgress = &progressClip;;

        Progress();
        ~Progress();
/*        int x = 150;
        int y = 25;
*/

};


#endif // PROGRESS_H_INCLUDED

#ifndef _BUTTON_H
#define _BUTTON_H

#include "SDL2/SDL_mixer.h"

#include "LTexture.h"
#include "Enum.h"

extern DisplayType gDisplayType;

class Button: public LTexture {
    private:
        SDL_Point pos;
        DisplayType mDisplayType;
        MusicType mMusicType;
    public:
        void setPosX(double);
        void setPosY(double);
        void setMDisplayType(DisplayType);
        void setMMusicType(MusicType);
        double getWidth();
        double getHeight();
        SDL_Point getPos();
        bool handleEvent(const SDL_Event &eventListener);
};

#endif // _BUTTON_H

#include "Button.h"

void Button::setPosX(double x) {
    pos.x = x;
}

void Button::setPosY(double y) {
    pos.y = y;
}

double Button::getWidth() {
    return mWidth;
}

double Button::getHeight() {
    return mHeight;
}

SDL_Point Button::getPos(){
    return pos;
}

void Button::handleEvent(const SDL_Event &eventListener) {
    if (eventListener.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        bool inside = true;
        if (x < pos.x) inside = false;
        else if (x > pos.x + mWidth) inside = false;
        else if (y < pos.y) inside = false;
        else if (y > pos.y + mHeight) inside = false;
        if (inside) {
            gDisplayType = mDisplayType;
            switch (mMusicType) {
                case MUSIC_PLAY:
                    break;
                case MUSIC_PAUSE:
                    Mix_PauseMusic();
                    break;
                case MUSIC_RESUME:
                    Mix_ResumeMusic();
                    break;
                case MUSIC_HALT:
                    Mix_HaltMusic();
                    break;
            }
        }
    }
}

void Button::setMDisplayType(DisplayType m) {
    mDisplayType = m;
}

void Button::setMMusicType(MusicType m) {
    mMusicType = m;
}

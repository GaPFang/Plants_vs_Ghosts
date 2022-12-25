#ifndef _LTEXTURE_H
#define _LTEXTURE_H

#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL2/SDL_image.h"

class LTexture{
	public:
	    LTexture();
	    ~LTexture() {free();}
		void loadFromFile (std::string path, SDL_Renderer*);
		void free();
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );
		void render( int x, int y, SDL_Renderer*, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void setWidth(int);
		void setHeight(int);
        SDL_Texture* getmTexture() { return mTexture; }

	protected:
        SDL_Texture* mTexture = NULL;
		int mWidth;
		int mHeight;
};

#endif // _LTEXTURE_H

#include "LTexture.h"

LTexture::LTexture(){}

void LTexture::free(){
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::loadFromFile (std::string path, SDL_Renderer *gRenderer) {
	//Get rid of preexisting texture
	free();
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
        /*SDL_Rect stretchRect;
        stretchRect.x = 0;
        stretchRect.y = 0;
        stretchRect.w = BUTTON_WIDTH;
        stretchRect.h = BUTTON_HEIGHT;
        SDL_BlitScaled( loadedSurface, NULL, loadedSurface, &stretchRect );*/

		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue ) {
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending ) {
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha ) {
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Renderer *currentRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	/*if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/
	SDL_RenderCopyEx( currentRenderer, mTexture, clip, &renderQuad, angle, center, flip );
	/*SDL_RenderCopyEx(SDL_Renderer * currentRenderer,
                   SDL_Texture * mTexture,
                   const SDL_Rect * srcRect,
                   const SDL_Rect * dstRect,
                   const double angle,
                   const SDL_Point *center,
                   const SDL_RendererFlip flip);*/
}

void LTexture::setWidth(int w) {
    mWidth = w;
}

void LTexture::setHeight(int h) {
    mHeight = h;
}

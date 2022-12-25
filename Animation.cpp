#include "Animation.h"
Animation::Animation(){}

/*Animation::Animation(SDL_Renderer* renderer){
	//Initialize
    gameRenderer = renderer;
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}*/

Animation::~Animation(){
	//Deallocate
	free();
}


/*bool Animation::loadFromFile(std::string path, Animation &texture){    // 2nd parameter is to determine which texture to free (can be empty or itself)
	free(texture);


	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} else {
        newTexture = SDL_CreateTextureFromSurface(texture.gameRenderer, loadedSurface );
		if( newTexture == NULL ){
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		} else {
			//Get image dimensions
			mWidth = loadedSurface->w / 2;
			mHeight = loadedSurface->h / 2;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}*/


/*void Animation::resetmTexture(){
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}*/

/*SDL_Texture* Animation::getmTexture(){
    return mTexture;
}*/

void Animation::animationRender( int x, int y, SDL_Renderer *currentRenderer, SDL_Rect* clip ){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mWidth};

	//Set clip rendering dimensions
	/*if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/

	//Render to screen
	SDL_RenderCopy( currentRenderer, gSpriteSheetTexture[animationType], clip, &renderQuad );
}

int Animation::getWidth(){
	return mWidth;
}

int Animation::getHeight(){
	return mHeight;
}

void Animation::setAlpha(Uint8 alpha) {
    for (int i = 0; i < ANIMATIONTYPE_TOTAL; i++) {
        SDL_SetTextureAlphaMod( gSpriteSheetTexture[i], alpha);
    }
}

/* bool Animation::init(){
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}

            //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags )){
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
    }

	return success;
}
*/

void Animation::animationLoadFromFile(std::string src, SDL_Renderer *gRenderer){    //set sprite clips later
    //Get rid of preexisting texture
	free();
	//The final texture
	SDL_Texture* newTexture[ANIMATIONTYPE_TOTAL] = {NULL};

	//Load image at specified path
	for (int i = 0; i < ANIMATIONTYPE_TOTAL; i++) {
        SDL_Surface* loadedSurface = IMG_Load( src.c_str() );
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: %s\n", src.c_str(), IMG_GetError() );
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
            newTexture[i] = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
            if( newTexture[i] == NULL )
            {
                printf( "Unable to create texture from %s! SDL Error: %s\n", src.c_str(), SDL_GetError() );
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

        gSpriteSheetTexture[i] = newTexture[i];
	}
	for(int i = 0; i < ANIMATION_FRAMES; i++){
        gSpriteClips[ i ].x = (i % 5) * mWidth / 5;
        gSpriteClips[ i ].y = (i / 5) * mHeight / 4;
        gSpriteClips[ i ].w = mWidth / 5;
        gSpriteClips[ i ].h = mHeight / 4;
    }
}

void Animation::free(){
	//Free texture if it exists
	for (int i = 0; i < ANIMATIONTYPE_TOTAL; i++){
        SDL_DestroyTexture(gSpriteSheetTexture[i]);
    }
    for (int i = 0; i < ANIMATION_FRAMES; i++) {
        gSpriteSheetTexture[i] = NULL;
    }
    mWidth = 0;
    mHeight = 0;
    //texture.resetmTexture();
    //texture.start = false;
}

//-------movement functions--------------
/*void Animation::move(int code, Animation &gSpriteSheetTexture){  //this will be called before startAnimation
    startAnimation(moving[code], true, gSpriteSheetTexture);   // passes the img src to startAnimation
}
void Animation::attack(int code, Animation &gSpriteSheetTexture){  //this will be called before startAnimation
    startAnimation(attacking[code], true, gSpriteSheetTexture);   // passes the img src to startAnimation
}
void Animation::die(int code, Animation &gSpriteSheetTexture){  //this will be called before startAnimation
    startAnimation(dying[code], true, gSpriteSheetTexture);   // passes the img src to startAnimation
}*/
/*void Animation::damaged(int code, Animation &gSpriteSheetTexture){  //this will be called before startAnimation
    startAnimation(damaging[code], true, gSpriteSheetTexture);   // passes the img src to startAnimation
}*/
//----------------------------------------------

int Animation::getFrame() {
    return frame;
}

AnimationType Animation::getAnimationType() {
    return animationType;
}

void Animation::setAnimationType(AnimationType t) {
    animationType = t;
}
/*void Animation::stop(){
    start = false;
}*/


SDL_Rect* Animation::getCurrentClip(){
    SDL_Rect *currentClip;
    if(frame / ANIMATION_FRAMES < 16){
        currentClip = &gSpriteClips[ frame / ANIMATION_FRAMES ];
    } else {
        currentClip = &gSpriteClips[0];
    }
    if (gDisplayType == MAINGAME) {
        frame += animationSpeed[animationType];
        if( frame >=  ANIMATION_FRAMES * movementInterval[animationType]) {
            frame = 0;
        }
    }
    return currentClip;
}

//const int Animation::ANIMATION_FRAMES = 16;


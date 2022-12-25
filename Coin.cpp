#include "Coin.h"
#include "Variables.h"

extern DisplayType gDisplayType;

bool Coin::loadMedia(std::string Text, SDL_Renderer* gRenderer){
    //Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont( "ARCADECLASSIC.ttf", 28 );
	if( gFont == NULL ){
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if( !(loadFromRenderedText( Text, gRenderer, textColor )) ){
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}

bool Coin::loadFromRenderedText( std::string textureText, SDL_Renderer* gRenderer, SDL_Color textColor){

 	//Render text surface
	//Get rid of preexisting texture

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL ){
			printf( "Unable to create texture from rendered text SDL Error: %s\n", SDL_GetError() );
		} else {
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	//Return success
	return mTexture != NULL;
}

void Coin::render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer, SDL_Texture* mTexture){
	//Set rendering space and render to screen
	int Width = 25;
	int Height = 25;
	SDL_Rect renderQuad = { x, y, Width, Height };

	//Set clip rendering dimensions
	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, 0, coinPos, 0, 0, SDL_FLIP_NONE);
}

bool Coin::init(){
	//Initialization flag
	bool success = true;

    //Initialize SDL_ttf
    if( TTF_Init() == -1 ){
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }

    coinRect.x = 300;
    coinRect.y = 0;
    coinRect.w = 100;
    coinRect.h = 100;


    iTick = SDL_GetTicks();
	return success;
}

void Coin::print(SDL_Renderer* gameRenderer){
    std::ostringstream os;
    os << currentCoin;
    loadMedia(os.str(), gameRenderer);
    render(10, 10, NULL, gameRenderer, getmTexture());
}

void Coin::coinCountUp(){
    if(gDisplayType == PAUSE){
        if(pauseTickDefined == false){
            pauseTickDefined = true;
            pauseTick = SDL_GetTicks();
        }
    } else if(gDisplayType == MAINGAME && pauseTickDefined == true){
        pauseTickDefined = false;
        iTick += SDL_GetTicks() - pauseTick;
        if(SDL_GetTicks() - iTick >= coinInterval){
            iTick = SDL_GetTicks();
            currentCoin += 50;
        }
    } else if(gameStarted == false && gDisplayType == MAINGAME){
        gameStarted = true;
        iTick = SDL_GetTicks();
        if(SDL_GetTicks() - iTick >= coinInterval){
            iTick = SDL_GetTicks();
            currentCoin += 50;
        }
    } else if(gameStarted == true && gDisplayType == MAINGAME){
        if(SDL_GetTicks() - iTick >= coinInterval){
            iTick = SDL_GetTicks();
            currentCoin += 50;
        }
    }


}

void Coin::deductCoin(int price){
    currentCoin -= price;
}

int Coin::getCurrentCoin() {
    return currentCoin;
}

void Coin::setCurrentCoin() {
    currentCoin = 50;
}

int Coin::currentCoin = 50;

#include "Game.h"

Game::Game(){
    time(&num);
    playButton.setPosX(350);
    playButton.setPosY(80);
    playButton.setMDisplayType(LEVEL_SELECTION);
    playButton.setMMusicType(MUSIC_PLAY);
    pauseButton.setPosX(SCREEN_WIDTH - 80);
    pauseButton.setPosY(0);
    pauseButton.setMDisplayType(PAUSE);
    pauseButton.setMMusicType(MUSIC_PLAY);
    resumeButton.setPosX(553);
    resumeButton.setPosY(152);
    resumeButton.setMDisplayType(MAINGAME);
    resumeButton.setMMusicType(MUSIC_RESUME);
    replayButton.setPosX(553);
    replayButton.setPosY(262);
    replayButton.setMDisplayType(MAINGAME);
    replayButton.setMMusicType(MUSIC_HALT);
    exitButton.setPosX(553);
    exitButton.setPosY(487);
    exitButton.setMDisplayType(LEVEL_SELECTION);
    exitButton.setMMusicType(MUSIC_HALT);
    for (int i = 0; i < 5; i++) {
        commodity[i].setPosX(commodity[i].getGPos().x);
        commodity[i].setPosY(commodity[i].getGPos().y + commodity[i].getHeight() * i);
        commodity[i].setMPlantType(PlantType(i));
        commodity[i].setCDinterval(5000 + 1500 * i, i);
        level[i].setPosX(25 + 175 * (i + 1));
        level[i].setPosY(250);
        level[i].setMDisplayType(MAINGAME);
        level[i].setMMusicType(MUSIC_HALT);
        mower[i].setRow(i);
        mower[i].setPos();
        for (int j = 0; j < 20; j++) {
            ghost[i][j].setRow(i);
            ghost[i][j].setID(j);
            ghost[i][j].setPos();
            ghost[i][j].setMoving(false);
        }
        for (int j = 0; j < 9; j++) {
            grid[i][j].setRow(i);
            grid[i][j].setColumn(j);
            grid[i][j].setPos();
            sunflower[i][j].setRow(i);
            sunflower[i][j].setColumn(j);
            sunflower[i][j].setPos();
            sunflower[i][j].setHP(142);
            sunflower[i][j].setAnimationType(MOVING);
            pea[i][j].setRow(i);
            pea[i][j].setColumn(j);
            pea[i][j].setPos();
            pea[i][j].setHP(142);
            nut[i][j].setRow(i);
            nut[i][j].setColumn(j);
            nut[i][j].setPos();
            nut[i][j].setHP(142);
            nut[i][j].setAnimationType(MOVING);
            watermelonGeneratorFront[i][j].setRow(i);
            watermelonGeneratorFront[i][j].setColumn(j);
            watermelonGeneratorFront[i][j].setPos();
            watermelonGeneratorFront[i][j].setHP(150);
            watermelonGeneratorBack[i][j].setRow(i);
            watermelonGeneratorBack[i][j].setColumn(j);
            watermelonGeneratorBack[i][j].setPos();
            watermelon[i][j].setStartPosX(watermelonGeneratorFront[i][j].getPos().x);
            watermelon[i][j].setStartPosY(watermelonGeneratorFront[i][j].getPos().y);
            watermelon[i][j].setNowPos();
            girl[i][j].setRow(i);
            girl[i][j].setColumn(j);
            girl[i][j].setPos();
            girl[i][j].setAnimationType(ATTACKTING);
            girl[i][j].setHP(142);
            for (int k = 0; k < 2; k++) {
                peaBullet[i][j][k].setStartPosX(pea[i][j].getPos().x + pea[i][j].getWidth() * 2 / 3);
                peaBullet[i][j][k].setStartPosY(pea[i][j].getPos().y + pea[i][j].getHeight() * 1 / 4);
                peaBullet[i][j][k].setNowPos();
            }
        }
    }
};

void Game::init() {
    coin.init();
    progressBar.progressBarInit();
    progressBar.setGameLength(10000);
	SDL_Init( SDL_INIT_VIDEO );
	gameRenderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
}

void Game::loadMedia() {
    //std::string path;
	menuBackgroundTexture.loadFromFile("img/menu.jpg", gameRenderer);
	levelSelectionBackgroundTexture.loadFromFile("img/levelSelection.png", gameRenderer);
	mainGameBackgroundTexture.loadFromFile("img/backgroundNormal.png", gameRenderer);
	pauseBackgroundTexture.loadFromFile("img/pause.jpg", gameRenderer);
    winGame.loadFromFile("img/win.jpg", gameRenderer);
    loseGame.loadFromFile("img/lose.jpg", gameRenderer);
	playButton.loadFromFile("img/playButton.png", gameRenderer);
	pauseButton.loadFromFile("img/pauseButton.png", gameRenderer);
	resumeButton.loadFromFile("img/resumeButton.jpg", gameRenderer);
	replayButton.loadFromFile("img/replayButton.jpg", gameRenderer);
	exitButton.loadFromFile("img/exitButton.jpg", gameRenderer);
	level[0].loadFromFile("img/level1.png", gameRenderer);
	level[1].loadFromFile("img/level2.png", gameRenderer);
	level[2].loadFromFile("img/level3.png", gameRenderer);
	level[3].loadFromFile("img/level4.png", gameRenderer);
	level[4].loadFromFile("img/level5.png", gameRenderer);
	shovel.loadFromFile("img/shovel.jpg", gameRenderer);
	progressBackground.loadFromFile("img/Progress.png", gameRenderer);
	progressBar.loadFromFile("img/Progress bar.png", gameRenderer);

	//coin.load
	/*for (int i = 0; i < PLANT_TOTAL; i++) {
        cin >> path;
        commodity[i].loadFromFile("img/backgroundTemp.png", plantRenderer[i]);
	}*/
	commodity[0].loadFromFile("img/sunflowerShop.png", gameRenderer);
	commodity[1].loadFromFile("img/appleTreeShop.png", gameRenderer);
	commodity[2].loadFromFile("img/nutShop.png", gameRenderer);
	commodity[3].loadFromFile("img/watermelonGeneratorShop.png", gameRenderer);
	commodity[4].loadFromFile("img/plantGirlShop.png", gameRenderer);
	plantFollowingMouse[0].loadFromFile("img/sunflowerShop.png", gameRenderer);
	plantFollowingMouse[1].loadFromFile("img/appleTreeShop.png", gameRenderer);
	plantFollowingMouse[2].loadFromFile("img/nutShop.png", gameRenderer);
	plantFollowingMouse[3].loadFromFile("img/watermelonGeneratorShop.png", gameRenderer);
	plantFollowingMouse[4].loadFromFile("img/plantGirlShop.png", gameRenderer);
    for (int i = 0; i < 5; i++) {
        mower[i].loadFromFile("img/mower.png", gameRenderer);
        for (int j = 0; j < 20; j++) {
            ghost[i][j].animationLoadFromFile("img/whiteGhost.png", gameRenderer);
        }
        for (int j = 0; j < 9; j++) {
            sunflower[i][j].animationLoadFromFile("img/sunflowerAnimation.png", gameRenderer);
            pea[i][j].animationLoadFromFile("img/appleTreeAttack.png", gameRenderer);
            pea[i][j].loadFromFile("img/appleTreeShop.png", gameRenderer);
            nut[i][j].animationLoadFromFile("img/nutStand.png", gameRenderer);
            watermelonGeneratorFront[i][j].loadFromFile("img/watermelonGeneratorFront.png", gameRenderer);
            watermelonGeneratorBack[i][j].loadFromFile("img/watermelonGeneratorBack.png", gameRenderer);
            watermelon[i][j].animationLoadFromFile("img/watermelonRolling.png", gameRenderer);
            girl[i][j].animationLoadFromFile("img/plantGirlAttack.png", gameRenderer);
            girl[i][j].loadFromFile("img/plantGirlShop.png", gameRenderer);
            for (int k = 0; k < 2; k++) {
                peaBullet[i][j][k].loadFromFile("img/appleBullet.png", gameRenderer);
            }
        }
	}
    menuBackgroundTexture.setWidth(SCREEN_WIDTH);
    menuBackgroundTexture.setHeight(SCREEN_HEIGHT);
	levelSelectionBackgroundTexture.setWidth(SCREEN_WIDTH);
	levelSelectionBackgroundTexture.setHeight(SCREEN_HEIGHT);
    mainGameBackgroundTexture.setWidth(SCREEN_WIDTH);
    mainGameBackgroundTexture.setHeight(SCREEN_HEIGHT);
    pauseBackgroundTexture.setWidth(300);
    pauseBackgroundTexture.setHeight(500);
    playButton.setWidth(500);
    playButton.setHeight(200);
    pauseButton.setWidth(80);
    pauseButton.setHeight(80);
    resumeButton.setWidth(210);
    resumeButton.setHeight(85);
    replayButton.setWidth(210);
    replayButton.setHeight(85);
    exitButton.setWidth(210);
    exitButton.setHeight(85);
    shovel.setWidth(shovel.getWidth());
    shovel.setHeight(shovel.getHeight());
    for (int i = 0; i < PLANT_TOTAL; i++) {
        commodity[i].setWidth(commodity[i].getWidth());
        commodity[i].setHeight(commodity[i].getHeight());
        plantFollowingMouse[i].setWidth(plantFollowingMouse[i].getWidth());
        plantFollowingMouse[i].setHeight(plantFollowingMouse[i].getHeight());
    }
    for (int i = 0; i < 5; i++) {
        level[i].setWidth(150);
        level[i].setHeight(150);
        mower[i].setWidth(mower[i].getWidth());
        mower[i].setHeight(mower[i].getHeight());
        for (int j = 0; j < 20; j++) {
            ghost[i][j].setWidth(ghost[i][j].getWidth());
            ghost[i][j].setHeight(ghost[i][j].getHeight());
        }
        for (int j = 0; j < 9; j++) {
            sunflower[i][j].setWidth(sunflower[i][j].getWidth());
            sunflower[i][j].setHeight(sunflower[i][j].getHeight());
            //grid[i][j].setWidth(grid[i][j].getWidth());
            //grid[i][j].setHeight(grid[i][j].getHeight());
            pea[i][j].setWidth(pea[i][j].getWidth());
            pea[i][j].setHeight(pea[i][j].getHeight());
            nut[i][j].setWidth(nut[i][j].getWidth());
            nut[i][j].setHeight(nut[i][j].getHeight());
            watermelonGeneratorFront[i][j].setWidth(watermelonGeneratorFront[i][j].getWidth());
            watermelonGeneratorFront[i][j].setHeight(watermelonGeneratorFront[i][j].getHeight());
            //watermelonGeneratorBack[i][j].setWidth(watermelonGeneratorBack[i][j].getWidth());
            //watermelonGeneratorBack[i][j].setHeight(watermelonGeneratorBack[i][j].getHeight());
            //watermelon[i][j].setWidth(watermelonGeneratorBack[i][j].getWidth() * 1.5);
            //watermelon[i][j].setHeight(watermelonGeneratorBack[i][j].getHeight() * 1.5);
            girl[i][j].setWidth(girl[i][j].getWidth());
            girl[i][j].setHeight(girl[i][j].getHeight());
            for (int k = 0; k < 2; k++) {
                peaBullet[i][j][k].setWidth(peaBullet[i][j][k].getWidth());
                peaBullet[i][j][k].setHeight(peaBullet[i][j][k].getHeight());
            }
        }
	}
	menuMusic = Mix_LoadMUS( "sound/menuMusic.mp3" );
	mainGameMusic = Mix_LoadMUS( "sound/mainGameMusic.mp3" );
    //gFont = TTF_OpenFont( "font/font1.ttf", 28 );
    SDL_Color textColor = { 0, 0, 0, 255 };
    //moneyTextTexture.
}

void Game::close() {
	mainGameBackgroundTexture.free();
	SDL_DestroyRenderer( gameRenderer );
	gameRenderer = NULL;
	//SDL_DestroyRenderer( autoRenderer );
	//autoRenderer = NULL;
}

void Game::initRenderPresent(){
    SDL_RenderPresent( gameRenderer );
}

void Game::plantRenderPresent(){

}

void Game::eventPrepare(const SDL_Event& eventListener) {
    if (gDisplayType == MAINGAME) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j].handleEvent(eventListener);
                if (commodity[i].getReady()) commodity[i].handleEvent(eventListener);
            }
        }
        if (gPlantType != PLANT_TOTAL) {
            plantFollowingMouse[gPlantType].followingMouse();
        }
        pauseButton.handleEvent(eventListener);
        shovel.handleEvent(eventListener);
    } else if (gDisplayType == MENU) {
        playButton.handleEvent(eventListener);
    } else if (gDisplayType == LEVEL_SELECTION) {
        for (int i = 0; i < 5; i++) {
            level[i].handleEvent(eventListener);
        }
    } else if (gDisplayType == PAUSE) {
        resumeButton.handleEvent(eventListener);
        if (replayButton.handleEvent(eventListener) || exitButton.handleEvent(eventListener)) {
            time(&num);
            count = 0;
            coin.setCurrentCoin();
            for (int i = 0; i < 5; i++) {
                mower[i].setPos();
                for (int j = 0; j < 20; j++) {
                    ghost[i][j].setPos();
                    ghost[i][j].setMoving(false);
                }
                for (int j = 0; j < 9; j++) {
                    sunflower[i][j].setHP(100);
                    pea[i][j].setHP(100);
                    nut[i][j].setHP(1000);
                    watermelonGeneratorFront[i][j].setHP(150);
                    girl[i][j].setHP(30);
                    for (int k = 0; k < 2; k++) {
                        peaBullet[i][j][k].setNowPos();
                    }
                }
            }
        }
    }
}

void Game::autoPrepare() {
    coin.coinCountUp();
    if (gDisplayType == MAINGAME) {
        progressBar.setTicksAfterStart();
        progressBar.setProgress();
        if (gPlantType != PLANT_TOTAL) {
            plantFollowingMouse[gPlantType].followingMouse();
        }
        if (usingShovel) {
            shovel.followingMouse();
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                pea[i][j].setAnimationType(RESTING);
                watermelonGeneratorFront[i][j].setAnimationType(RESTING);
                girl[i][j].setAnimationType(RESTING);
                if (existingEnemy[i]) {
                    pea[i][j].setAnimationType(ATTACKTING);
                    watermelonGeneratorFront[i][j].setAnimationType(ATTACKTING);
                    if (grid[i][j].getMPlantType() == PEA) {
                        if (pea[i][j].getFrame() == 180) {
                            if (peaBullet[i][j][0].getReady()) {
                                peaBullet[i][j][0].setMoving(true);
                                peaBullet[i][j][0].setReady(false);
                            } else if (peaBullet[i][j][1].getReady()) {
                                peaBullet[i][j][1].setMoving(true);
                                peaBullet[i][j][1].setReady(false);
                            }
                        }
                    } else if (grid[i][j].getMPlantType() == WATERMELON) {
                        if (watermelon[i][j].getReady()) {
                            watermelon[i][j].setMoving(true);
                            watermelon[i][j].setReady(false);
                        }
                    }
                }
            }
            if (eNum[i] > killedeNum[i]) existingEnemy[i] = true;
            else existingEnemy[i] = false;
            for (int j = killedeNum[i]; j < 20; j++) {
                if(ghost[i][j].getMoving() && !checkCollision(ghost[i][j], i, (ghost[i][j].getPos().x - grid[i][0].getPos().x) / grid[i][0].getWidth())) {
                    ghost[i][j].move();
                }
                ghost[i][j].setMoving(false);
                checkCollision(ghost[i][j], mower[i]);
            }
            if (count < 100){
                if (count) {
                    int time = 5000 - 7 * count * count;
                    if(SDL_GetTicks() - iTick >= time){
                        iTick = SDL_GetTicks();
                        ghost[eSequence[num]][eNum[eSequence[num]]].setMoving(true);
                        eNum[eSequence[num]]++;
                        count++;
                        num++;
                        num %= 100;
                    }
                } else {
                    iTick = SDL_GetTicks();
                    count++;
                }
            }
            commodity[i].setReady(i);
            if (mower[i].getMoving()) mower[i].move();
            if (mower[i].getPos().x > SCREEN_WIDTH + 200) {
                mower[i].setMoving(false);
            }
            for (int j = 0; j < 9; j++) {
                if (watermelon[i][j].getMoving()) {
                    watermelon[i][j].move();
                    checkCollision(ghost[i][killedeNum[i]], watermelon[i][j], grid[i][j].getMPlantType());
                }
                if (watermelon[i][j].getNowPos().x > SCREEN_WIDTH) {
                    watermelon[i][j].setNowPos();
                    watermelon[i][j].setMoving(false);
                    watermelon[i][j].setReady(true);
                }
                for (int k = 0; k < 2; k++) {
                    if (peaBullet[i][j][k].getMoving()) {
                        peaBullet[i][j][k].move();
                        checkCollision(ghost[i][killedeNum[i]], peaBullet[i][j][k], grid[i][j].getMPlantType());
                    }
                    if (peaBullet[i][j][k].getNowPos().x > SCREEN_WIDTH) {
                        peaBullet[i][j][k].setNowPos();
                        peaBullet[i][j][k].setMoving(false);
                        peaBullet[i][j][k].setReady(true);
                    }
                }
                gameEnd(i, j);
            }
        }
        if( Mix_PlayingMusic() == 0 ) {
            Mix_PlayMusic( mainGameMusic, -1 );
        }
    } else if (gDisplayType == MENU || gDisplayType == LEVEL_SELECTION) {
        if( Mix_PlayingMusic() == 0 ) {
            Mix_PlayMusic( menuMusic, -1 );
        }
    }
}

void Game::renderPresent() {
    SDL_RenderClear(gameRenderer);
    if (gDisplayType == MAINGAME) {
        mainGameBackgroundTexture.render(0, 0, gameRenderer);
        pauseButton.render(pauseButton.getPos().x, pauseButton.getPos().y, gameRenderer);
        shovel.render(shovel.getGPos().x, shovel.getGPos().y, gameRenderer);
        for (int i = 0; i < PLANT_TOTAL; i++) {
            commodity[i].render(commodity[i].getMPos().x, commodity[i].getMPos().y, gameRenderer);
        }
        for (int i = 0; i < 5; i++) {
            mower[i].render(mower[i].getPos().x, mower[i].getPos().y, gameRenderer);
            for (int j = 8; j >= 0; j--) {
                //grid[i][j].render(grid[i][j].getPos().x, grid[i][j].getPos().y, gameRenderer);
                if (grid[i][j].getMPlantType() == SUNFLOWER) {
                    sunflower[i][j].animationRender(sunflower[i][j].getPos().x, sunflower[i][j].getPos().y, gameRenderer, sunflower[i][j].getCurrentClip());
                } else if (grid[i][j].getMPlantType() == PEA) {
                    if (pea[i][j].getAnimationType() == RESTING) {
                        pea[i][j].render(girl[i][j].getPos().x, pea[i][j].getPos().y, gameRenderer);
                    } else {
                        pea[i][j].animationRender(pea[i][j].getPos().x, pea[i][j].getPos().y, gameRenderer, pea[i][j].getCurrentClip());
                    }
                } else if (grid[i][j].getMPlantType() == NUT) {
                    nut[i][j].animationRender(nut[i][j].getPos().x, nut[i][j].getPos().y, gameRenderer, nut[i][j].getCurrentClip());
                } else if (grid[i][j].getMPlantType() == WATERMELON) {
                    watermelonGeneratorBack[i][j].render(watermelonGeneratorBack[i][j].getPos().x, watermelonGeneratorBack[i][j].getPos().y, gameRenderer);
                    watermelon[i][j].animationRender(watermelon[i][j].getNowPos().x, watermelon[i][j].getNowPos().y, gameRenderer, watermelon[i][j].getCurrentClip());
                    watermelonGeneratorFront[i][j].render(watermelonGeneratorFront[i][j].getPos().x, watermelonGeneratorFront[i][j].getPos().y, gameRenderer);
                } else if (grid[i][j].getMPlantType() == GIRL) {
                    if (girl[i][j].getAnimationType() == RESTING) {
                        girl[i][j].render(girl[i][j].getPos().x, girl[i][j].getPos().y, gameRenderer);
                    } else {
                        girl[i][j].animationRender(girl[i][j].getPos().x, girl[i][j].getPos().y, gameRenderer, girl[i][j].getCurrentClip());
                    }
                }
                for (int k = 0; k < 2; k++) {
                    if (peaBullet[i][j][k].getMoving()) {
                        peaBullet[i][j][k].render(peaBullet[i][j][k].getNowPos().x, peaBullet[i][j][k].getNowPos().y, gameRenderer);
                    }
                }
            }
            for (int j = 0; j < 20; j++) {
                ghost[i][j].animationRender(ghost[i][j].getPos().x, ghost[i][j].getPos().y, gameRenderer, ghost[i][j].getCurrentClip());
            }
        }
        if (gPlantType != PLANT_TOTAL) {
            plantFollowingMouse[gPlantType].render(plantFollowingMouse[gPlantType].getPos().x, plantFollowingMouse[gPlantType].getPos().y, gameRenderer);
        }
        coin.print(gameRenderer);   //coins
        coin.coinCountUp();    //coin++
        progressBackground.progressBackgroundInit();        //progress bar
        progressBackground.render(575, 20, gameRenderer, progressBackground.currentProgress);       //progress bar
        progressBar.setTicksAfterStart();
        progressBar.setProgress();      //progress bar
        progressBar.render(580, 25, gameRenderer, progressBar.currentProgress);     //progress bar
        if (usingShovel) shovel.render(shovel.getMPos().x, shovel.getMPos().y, gameRenderer);
    } else if (gDisplayType == MENU) {
        menuBackgroundTexture.render(0, 0, gameRenderer);
        playButton.render(playButton.getPos().x, playButton.getPos().y, gameRenderer);
    } else if (gDisplayType == LEVEL_SELECTION) {
        levelSelectionBackgroundTexture.render(0, 0, gameRenderer);
        for (int i = 0; i < 5; i++) {
            level[i].render(level[i].getPos().x, level[i].getPos().y, gameRenderer);
        }
    } else if (gDisplayType == PAUSE) {
        mainGameBackgroundTexture.setAlpha(150);
        mainGameBackgroundTexture.render(0, 0, gameRenderer);
        mainGameBackgroundTexture.setAlpha(255);
        pauseButton.setAlpha(150);
        pauseButton.render(pauseButton.getPos().x, pauseButton.getPos().y, gameRenderer);
        pauseButton.setAlpha(255);
        progressBar.setTicksAfterStart();

        for (int i = 0; i < PLANT_TOTAL; i++) {
            commodity[i].setAlpha(150);
            commodity[i].render(commodity[i].getMPos().x, commodity[i].getMPos().y, gameRenderer);
            commodity[i].setAlpha(255);
        }
        for (int i = 0; i < 5; i++) {
            mower[i].setAlpha(150);
            mower[i].render(mower[i].getPos().x, mower[i].getPos().y, gameRenderer);
            mower[i].setAlpha(255);
            for (int j = 8; j >= 0; j--) {
                //grid[i][j].render(grid[i][j].getPos().x, grid[i][j].getPos().y, gameRenderer);
                if (grid[i][j].getMPlantType() == SUNFLOWER) {
                    for (int i = 0; i < ANIMATIONTYPE_TOTAL; i++)
                    sunflower[i][j].setAlpha(150);
                    sunflower[i][j].animationRender(sunflower[i][j].getPos().x, sunflower[i][j].getPos().y, gameRenderer, sunflower[i][j].getCurrentClip());
                    sunflower[i][j].setAlpha(255);
                } else if (grid[i][j].getMPlantType() == PEA) {
                    for (int i = 0; i < ANIMATIONTYPE_TOTAL; i++)
                    pea[i][j].setAlpha(150);
                    pea[i][j].animationRender(pea[i][j].getPos().x, pea[i][j].getPos().y, gameRenderer, pea[i][j].getCurrentClip());
                    pea[i][j].setAlpha(255);
                } else if (grid[i][j].getMPlantType() == NUT) {
                    nut[i][j].setAlpha(150);
                    nut[i][j].animationRender(nut[i][j].getPos().x, nut[i][j].getPos().y, gameRenderer, nut[i][j].getCurrentClip());
                    nut[i][j].setAlpha(255);
                } else if (grid[i][j].getMPlantType() == WATERMELON) {
                    watermelonGeneratorBack[i][j].setAlpha(150);
                    watermelonGeneratorBack[i][j].render(watermelonGeneratorBack[i][j].getPos().x, watermelonGeneratorBack[i][j].getPos().y, gameRenderer);
                    watermelonGeneratorBack[i][j].setAlpha(255);
                    watermelonGeneratorFront[i][j].setAlpha(150);
                    watermelonGeneratorFront[i][j].render(watermelonGeneratorFront[i][j].getPos().x, watermelonGeneratorFront[i][j].getPos().y, gameRenderer);
                    watermelonGeneratorFront[i][j].setAlpha(255);
                } else if (grid[i][j].getMPlantType() == GIRL) {
                    girl[i][j].setAlpha(150);
                    girl[i][j].animationRender(girl[i][j].getPos().x, girl[i][j].getPos().y, gameRenderer, girl[i][j].getCurrentClip());
                    girl[i][j].setAlpha(255);
                }
                for (int k = 0; k < 2; k++) {
                    if (peaBullet[i][j][k].getMoving()) {
                        peaBullet[i][j][k].setAlpha(150);
                        peaBullet[i][j][k].render(peaBullet[i][j][k].getNowPos().x, peaBullet[i][j][k].getNowPos().y, gameRenderer);
                        peaBullet[i][j][k].setAlpha(255);
                    }
                }
            }
            for (int j = 0; j < 20; j++) {
                ghost[i][j].setAlpha(150);
                ghost[i][j].animationRender(ghost[i][j].getPos().x, ghost[i][j].getPos().y, gameRenderer, ghost[i][j].getCurrentClip());
                ghost[i][j].setAlpha(255);
            }
        }
        if (gPlantType != PLANT_TOTAL) {
            plantFollowingMouse[gPlantType].setAlpha(150);
            plantFollowingMouse[gPlantType].render(plantFollowingMouse[gPlantType].getPos().x, plantFollowingMouse[gPlantType].getPos().y, gameRenderer);
            plantFollowingMouse[gPlantType].setAlpha(255);
        }
        pauseBackgroundTexture.render(500, 120, gameRenderer);
        resumeButton.render(resumeButton.getPos().x, resumeButton.getPos().y, gameRenderer);
        replayButton.render(replayButton.getPos().x, replayButton.getPos().y, gameRenderer);
        exitButton.render(exitButton.getPos().x, exitButton.getPos().y, gameRenderer);
    } else if(gDisplayType == WIN) {
        winGame.render(0, 0, gameRenderer);
    } else if(gDisplayType == LOSE){
        loseGame.render(0, 0, gameRenderer);
    }
    SDL_RenderPresent( gameRenderer );
}

void Game::clearRender(){

}

bool Game::checkCollision(Enemies &enemy, int i, int j){
    bool collided = false;

    if(j < 0 || j > 8) {
        collided = false;
        return collided;
    }

    if (grid[i][j].getMPlantType() != PLANT_TOTAL){    // change 1200 to the width of the image blat on the screen
        collided = true;
        /*if(enemy.ID == nutInvulnerableGhost && grid.getMPlantType() == NUT){        // nut & nutInvulnerableGhost are enum elements, maybe change(format) enum elements later
            enemy.resetCollide();
            grid[i][j].resetCollide();
        } else {*/
            enemy.setAnimationType(ATTACKTING);  // change this back to true when one of the two colliding objects died
            if (grid[i][j].getMPlantType() == GIRL) girl[i][j].setAnimationType(ATTACKTING);
            switch(grid[i][j].getMPlantType()) {
                case PEA:

                    pea[i][j].HPdamaged(enemy.getATK());
                    std::cout << "pea = " << pea[i][j].getHP() << std::endl;
                    if (pea[i][j].getHP() <= 0) {

                        grid[i][j].setMPlantType(PLANT_TOTAL);
                        pea[i][j].setHP(100);
                    }
                    break;
                case NUT:
                    nut[i][j].HPdamaged(enemy.getATK());
                    std::cout << "nut = " << nut[i][j].getHP() << std::endl;
                    if (nut[i][j].getHP() <= 0) {
                        grid[i][j].setMPlantType(PLANT_TOTAL);
                        nut[i][j].setHP(142);
                    }
                    break;
                case WATERMELON:
                    watermelonGeneratorFront[i][j].HPdamaged(enemy.getATK());
                    if (watermelonGeneratorFront[i][j].getHP() <= 0) {
                        grid[i][j].setMPlantType(PLANT_TOTAL);
                        watermelonGeneratorFront[i][j].setHP(150);
                    }
                    break;
                case GIRL:
                    girl[i][j].HPdamaged(enemy.getATK());
                    enemy.HPdamaged(girl[i][j].getATK());
                    std::cout << "GirlHP = " << girl[i][j].getHP() << std::endl;
                    if (girl[i][j].getHP() <= 0) {
                        grid[i][j].setMPlantType(PLANT_TOTAL);
                        girl[i][j].setHP(142);
                    }
                    break;
        }
    }
    return collided;
}

void Game::checkCollision(Enemies &enemy, PeaBullet &peaBullet, PlantType plantType){
    if(peaBullet.getNowPos().x - enemy.getPos().x > enemy.getWidth() / 4 && peaBullet.getNowPos().x - enemy.getPos().x < enemy.getWidth() * 3 / 4){
        enemy.HPdamaged(peaBullet.getATK());
        //-----------resetting peaBullet-----------
        if (plantType == PEA) {
            peaBullet.setNowPos();
            peaBullet.setMoving(false);
            peaBullet.setReady(true);
        }
        //-----------------------------------------
        if(enemy.getHP() <= 0){
            killedeNum[enemy.getRow()]++;
            enemy.setPos();
            enemy.setMoving(false);
        }
    }
}

void Game::checkCollision(Enemies &enemy, Mower &mower){
    if(enemy.getPos().x - mower.getPos().x < mower.getWidth() * 3 / 4 && enemy.getPos().x - mower.getPos().x > 0 && enemy.getPos().x < SCREEN_WIDTH){
        killedeNum[enemy.getRow()]++;
        enemy.setPos();
        enemy.setMoving(false);
        mower.setMoving(true);
    }
}

int Game::checkEnding() {
    if (count == 100) return 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < killedeNum[i]; j++) {
            if (ghost[i][j].getPos().x < grid[i][0].getPos().x - 100) {
                return 1;
            }
        }
    }
    return 0;
}

bool Game::gameEnd(int i, int j){
    int killedTotal = 0;
    for(int k = 0; k < 5; k++){
        killedTotal += killedeNum[k];
    }
    if(killedTotal == 100){
        gameEnded = true;
        gameWon = true;
        gameLose = false;
        gDisplayType = WIN;
        std::cout << gDisplayType << std::endl;
        return true;
    } else if(ghost[i][j].getPos().x /* < GIMME THIS COORDINATE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/){
        gameEnded = true;
        gameWon = false;
        gameLose = true;
        gDisplayType = LOSE;
        std::cout << gDisplayType << std::endl;
        return true;
    }
    return false;
}

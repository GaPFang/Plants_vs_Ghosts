#ifndef _ENUM_H
#define _ENUM_H

enum DisplayType {
    MENU,
    LEVEL_SELECTION,
    MAINGAME,
    PAUSE,
    SETTINGS,
    WIN,
    LOSE,
    DISPLAYTYPE_TOTAL
};

enum PlantType {
    SUNFLOWER,
	PEA,
	NUT,
	WATERMELON,
	GIRL,
	PLANT_TOTAL
};

enum AnimationType{
    MOVING,
    ATTACKTING,
    RESTING,
    ANIMATIONTYPE_TOTAL
};

enum MusicType {
    MUSIC_PLAY,
    MUSIC_PAUSE,
    MUSIC_RESUME,
    MUSIC_HALT,
    MUSIC_TOTAL
};

#endif // _ENUM_H

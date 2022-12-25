#ifndef _ENUM_H
#define _ENUM_H

enum DisplayType {
    MENU,
    LEVEL_SELECTION,
    MAINGAME,
    PAUSE,
    SETTINGS,
    DISPLAYTYPE_TOTAL
};

enum PlantType {
	PEA,
	NUT,
	GIRL,
	BANANA,
	CAT,
	PLANT_TOTAL
};

enum AnimationType{
    MOVING,
    ATTACKTING,
    DYING,
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

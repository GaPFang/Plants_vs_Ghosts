#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include "Coin.h"
#include "Enum.h"

extern bool usingShovel;
extern Coin coin;
extern int Price[5];
extern Uint32 CDtime[5];
extern bool existingEnemy[5];
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* Window;
extern DisplayType gDisplayType;
extern PlantType gPlantType;

#endif // VARIABLES_H_INCLUDED

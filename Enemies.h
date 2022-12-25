#ifndef ZOMBIES_H_INCLUDED
#define ZOMBIES_H_INCLUDED

#include "Animation.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Enemies: public Animation{
protected:
    static const double width, height;
    static const SDL_Point gPos;
    static const int A_SPD = 1;
    SDL_Point mPos;
    int HP = 100;
    const int ATK = 10;
    int row;
    int ID;
    bool ready = 1;
    bool moving = false;
    bool nutInvulnerable;
    //Uint32 startTime = SDL_GetTicks();
public:
    Enemies();
    ~Enemies();
    double getWidth();
    double getHeight();
    bool getMoving();
    void setMoving(bool);
    SDL_Point getPos();
    void setRow(int);
    void setID(int);
    void setPos();
    void move();
    bool collided;
    void HPdamaged(int damage);
    //Uint32 getTime();
    //void resetTime();
};

#endif // ZOMBIES_H_INCLUDED

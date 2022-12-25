#ifndef ZOMBIES_H_INCLUDED
#define ZOMBIES_H_INCLUDED

#include "Animation.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Enemies: public Animation{
protected:
    static const double width, height;
    static const SDL_Point gPos;
    static const int M_SPD;
    SDL_Point mPos;
    double HP = 100;
    const double ATK = 0.7;
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
    void HPdamaged(double damage);
    double getATK();
    double getHP();
    int getRow();
    //Uint32 getTime();
    //void resetTime();
};

#endif // ZOMBIES_H_INCLUDED

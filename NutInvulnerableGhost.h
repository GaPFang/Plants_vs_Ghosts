#ifndef NUTINVULNERABLEGHOST_H_INCLUDED
#define NUTINVULNERABLEGHOST_H_INCLUDED

#include "Enemies.h"

class NutInvulnerableGhost : public Enemies, public Animation{
    private:
        int HP;
        int ATK;
        int A_SPD;
        bool nutInvulnerable = true;

    public:
        int number;
        PlantType ID = NUTINVULNERABLEGHOST;
        void HPdamaged (int damage) {HP -= damage;}
        virtual void movingAnimation() = 0;
        virtual void attackAnimation() = 0;
        virtual void damagedAnimation() = 0;
        virtual void deathAnimation() = 0;
};




#endif // NUTINVULNERABLEGHOST_H_INCLUDED

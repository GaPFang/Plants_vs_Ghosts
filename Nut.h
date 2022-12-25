#ifndef _NUT_H
#define _NUT_H

#include "Plants.h"

class Nut: public Plants{
    private:
        AnimationType animationType = MOVING;
    public:
        Nut();
        ~Nut();
};

#endif // _NUT_H

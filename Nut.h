#ifndef _NUT_H
#define _NUT_H

#include "Plants.h"

class Nut: public Plants{
    private:
        int HP = 1000;
    public:
        Nut();
        ~Nut();
};

#endif // _NUT_H

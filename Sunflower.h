#ifndef _SUNFLOWER_H
#define _SUNFLOWER_H

#include "Plants.h"

class Sunflower: public Plants{
    private:
        int HP = 100;
    public:
        Sunflower();
        ~Sunflower();
};

#endif // _SUNFLOWER_H

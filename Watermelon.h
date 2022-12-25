#ifndef _WATERMELON_H
#define _WATERMELON_H

#include "Plants.h"

class Watermelon: public Plants{
    private:
        int HP = 150;
    public:
        Watermelon();
        ~Watermelon();
};

#endif // _WATERMELON_H

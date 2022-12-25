#ifndef _WATERMELON_H
#define _WATERMELON_H

#include "Plants.h"

class Watermelon: public Plants{
    private:
        AnimationType animationType = ATTACKTING;
    public:
        Watermelon();
        ~Watermelon();
};

#endif // _WATERMELON_H

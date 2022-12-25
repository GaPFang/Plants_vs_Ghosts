#ifndef _GIRL_H
#define _GIRL_H

#include "Plants.h"

class Girl: public Plants{
    private:
        AnimationType animationType = ATTACKTING;
    public:
        Girl();
        ~Girl();
};

#endif // _GIRL_H

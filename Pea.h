#ifndef _PEA_H
#define _PEA_H

#include "Plants.h"

class Pea: public Plants{
    private:
        AnimationType animationType = ATTACKTING;
    public:
        Pea();
        ~Pea();
};

#endif // _PEA_H
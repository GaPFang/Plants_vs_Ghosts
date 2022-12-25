#ifndef _GIRL_H
#define _GIRL_H

#include "Plants.h"

class Girl: public Plants{
    private:
        int HP = 30;
    public:
        Girl();
        ~Girl();
};

#endif // _GIRL_H

#ifndef _WATERMELONGENERATOR_H
#define _WATERMELONGENERATOR_H

#include "Plants.h"

class WatermelonGenerator: public Plants{
    private:
        int HP = 150;
    public:
        WatermelonGenerator();
        ~WatermelonGenerator();
};

#endif // _WATERMELONGENERATOR_H

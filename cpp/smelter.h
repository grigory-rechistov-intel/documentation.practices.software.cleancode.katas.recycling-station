#pragma once
// Predetermined recycling station. Do not change this file,
// it is outside of your control

#include "units.h"
class Garbage;

class Smelter {
    public:
    void smelt(Garbage *bucket);
};

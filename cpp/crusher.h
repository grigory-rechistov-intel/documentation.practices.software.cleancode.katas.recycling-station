#pragma once
// Predetermined recycling station. Do not change this file,
// it is outside of your control

#include "units.h"

class Garbage;

class Crusher {
    public:
    void wash(CubicMeter volume);
    void crush(Garbage *bucket);
};
#pragma once
// Predetermined recycling station. Do not change this file,
// it is outside of your control
#include "units.h"
#include "crusher.h"
#include "smelter.h"
#include <stdexcept>
#include <cstdio>

using GarbageProcessingException = std::runtime_error;


class Garbage {
    protected:
        bool is_recycled = false;
        virtual ~Garbage() = default;
};


class Glass: public Garbage {
    CubicMeter volume;
    public:
    Glass(CubicMeter volume_): volume(volume_) {}

    void cross(Crusher &crusher) {
        printf("Side effect: crossed %d m3\n", this->volume);
        crusher.wash(this->volume);
        crusher.crush(this);
        is_recycled = true;
    }
};

class ScrapMetal : public Garbage {
    Kilogram weight;
    public:
    ScrapMetal(Kilogram weight_): weight(weight_) {}

    void smelt(Smelter &smelter) {
        smelter.smelt(this);
        is_recycled = true;
    }
};

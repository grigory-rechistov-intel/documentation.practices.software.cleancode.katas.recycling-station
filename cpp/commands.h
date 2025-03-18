#pragma once

#include "garbage.h"
#include "smelter.h"
#include "crusher.h"

class Command {
    public:
    virtual void execute() = 0;
};


class CrushCommand : public Command {
    Glass &piece;
    Crusher &crusher;
    public:
    CrushCommand(Glass & glass_, Crusher & crusher_): piece(glass_), crusher(crusher_) {}
    virtual void execute() {
        piece.cross(crusher);
    }
};

class SmeltCommand : public Command {
    ScrapMetal &piece;
    Smelter &smelter;
    public:
    SmeltCommand(ScrapMetal & metal_, Smelter & smelter_): piece(metal_), smelter(smelter_) {}
    virtual void execute() {
        piece.smelt(smelter);
    }
};


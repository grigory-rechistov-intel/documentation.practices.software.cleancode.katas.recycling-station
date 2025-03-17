#pragma once
#include <vector>

class Garbage;
class Smelter;
class Crusher;
void recycle(std::vector<Garbage *> &garbage_load, Smelter &smelter,
        Crusher &crusher);

#include "recyclingstation.h"
#include "garbage.h"
#include "crusher.h"
#include "smelter.h"

void recycle(std::vector<Garbage *> &garbage_load,
             Smelter &smelter, Crusher &crusher) {
    for (auto piece: garbage_load) {
        if (dynamic_cast<Glass*>(piece)) {
            dynamic_cast<Glass*>(piece)->cross(crusher);
        } else if (dynamic_cast<ScrapMetal*>(piece)) {
            dynamic_cast<ScrapMetal*>(piece)->smelt(smelter);
        } else {
            throw GarbageProcessingException("Unknown garbage type, blow up");
        }
    }
}
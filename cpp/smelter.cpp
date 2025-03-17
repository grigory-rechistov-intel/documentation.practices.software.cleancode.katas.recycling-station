// Predetermined recycling station. Do not change this file,
// it is outside of your control
#include "smelter.h"
#include "garbage.h"

void Smelter::smelt(Garbage *bucket) {
    if (!dynamic_cast<ScrapMetal*>(bucket)) {
        throw GarbageProcessingException("Attempted to smelt non-metal");
    }
    printf("Side effect: smelting of %p performed\n", bucket);
}

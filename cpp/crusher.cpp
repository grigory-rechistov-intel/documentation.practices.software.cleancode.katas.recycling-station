// Predetermined recycling station. Do not change this file,
// it is outside of your control
#include "crusher.h"
#include "garbage.h"

void Crusher::wash(CubicMeter volume) {
    printf("Side effect: washing of %d m^3\n", volume);
}

void Crusher::crush(Garbage *bucket) {
    if (!dynamic_cast<Glass*>(bucket)) {
        throw GarbageProcessingException("Attempted to crush non-glass");
    }
    printf("Side effect: crushing of %p performed\n", bucket);
    }

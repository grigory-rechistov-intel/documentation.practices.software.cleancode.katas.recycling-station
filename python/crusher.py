# Predetermined recycling station. Do not change this file,
# it is outside of your control

from units import CubicMeter
from garbage import Glass, Garbage, GarbageProcessingException


class Crusher:
    def wash(self, volume: CubicMeter):
        print(f"Side effect: washing of {volume} m^3")

    def crush(self, bucket: Garbage):
        if not isinstance(bucket, Glass):
            raise GarbageProcessingException("Attempted to crush non-glass")
        print(f"Side effect: crushing of {bucket} performed")

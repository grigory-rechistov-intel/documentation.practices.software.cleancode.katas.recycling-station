# Predetermined recycling station. Do not change this file,
# it is outside of your control

from units import Kilogram
from garbage import Garbage, ScrapMetal, GarbageProcessingException


class Smelter:
    def smelt(self, bucket: Garbage):
        if not isinstance(bucket, ScrapMetal):
            raise GarbageProcessingException("Attempted to smelt non-metal")
        print(f"Side effect: smelting of {bucket} performed")

    def deoxidize(self, weight: Kilogram):
        print(f"Side effect: deoxidizing of {weight} kg")

    def derust(self, weight: Kilogram):
        print(f"Side effect: derusting of {weight} kg")

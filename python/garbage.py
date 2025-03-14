# Predetermined types of garbage. Do not change this file,
# it is outside of your control

from abc import ABC
from enum import Enum
from units import CubicMeter, Kilogram


class GarbageProcessingException(Exception):
    pass


class Garbage(ABC):
    def __init__(self):
        super().__init__()
        self.is_recycled: bool = False


class Glass(Garbage):
    def __init__(self, volume: CubicMeter):
        super().__init__()
        self.volume = volume

    def cross(self, crusher: "Crusher"):
        crusher.wash(self.volume)
        crusher.crush(self)
        self.is_recycled = True


MetalType = Enum('MetalType', [('Iron', 1), ('Aluminum', 2), ('Copper', 3)])


class ScrapMetal(Garbage):
    def __init__(self, metal: MetalType, weight: Kilogram):
        super().__init__()
        self.type = metal
        self.weight = weight

    def smelt(self, smelter: "Smelter"):
        match self.type:
            case MetalType.Iron:
                smelter.derust(self.weight)
            case MetalType.Aluminum:
                smelter.deoxidize(self.weight)
            case MetalType.Copper:
                pass  # there is no need to prepare copper
        smelter.smelt(self)
        self.is_recycled = True

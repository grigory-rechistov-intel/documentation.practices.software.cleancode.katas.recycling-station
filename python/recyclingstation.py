# Edit this file to add new type of garbage: Organic.
# It should be recycled by new Composter's method decompose().
# It should be processed # as part of input collection by the same functions:
# recycle() and better_recycle()

from abc import ABC, abstractmethod

from smelter import Smelter
from crusher import Crusher
from garbage import Garbage, ScrapMetal, Glass, GarbageProcessingException


def recycle(garbage_load: list[Garbage], smelter: Smelter, crusher: Crusher):
    for garbage in garbage_load:
        if isinstance(garbage, ScrapMetal):
            garbage.smelt(smelter)
        elif isinstance(garbage, Glass):
            garbage.cross(crusher)
        else:
            raise GarbageProcessingException("Unknown garbage type, blow up")


# =======================================

class RecycleCommand(ABC):
    @abstractmethod
    def __call__(self):
        pass


class SmeltCommand(RecycleCommand):
    def __init__(self, piece: ScrapMetal, smelter: Smelter):
        super().__init__()
        self.piece = piece
        self.smelter = smelter

    def __call__(self):
        self.piece.smelt(self.smelter)


class CrossCommand(RecycleCommand):
    def __init__(self, piece: Glass, crusher: Crusher):
        super().__init__()
        self.piece = piece
        self.crusher = crusher

    def __call__(self):
        self.piece.cross(self.crusher)


def better_recycle(garbage_commands: list[RecycleCommand]):
    for cmd in garbage_commands:
        cmd()

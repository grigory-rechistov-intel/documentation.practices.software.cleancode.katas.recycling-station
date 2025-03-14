# Edit this file to add new type of garbage: Organic.
# It should be recycled by new Composter's method decompose().
# It should be processed # as part of input collection by the same functions:
# recycle() and better_recycle()

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

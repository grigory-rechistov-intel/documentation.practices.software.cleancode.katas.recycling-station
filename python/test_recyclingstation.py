#!/usr/bin/env python3

import unittest

from garbage import MetalType, Garbage, ScrapMetal, Glass

from recyclingstation import Smelter, Crusher, recycle


class GarbageTests(unittest.TestCase):
    def test_constructors(self):
        self.assertTrue(Garbage())
        self.assertTrue(Glass(5))


class SideEffectIntegration(unittest.TestCase):
    def test_recycle(self):
        sm = Smelter()
        cr = Crusher()
        m1 = ScrapMetal(MetalType.Aluminum, weight=10)
        g2 = Glass(volume=3)

        load = [m1, g2]
        recycle(load, sm, cr)


if __name__ == "__main__":
    unittest.main()

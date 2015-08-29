from ctypes import *

testlib = CDLL("./test.so")

class MyPoint():
    def __init__(self, x, y):
        self.p = testlib.Point_new(x, y)

    def GetX(self):
        return testlib.Point_GetX(self.p)

    def GetY(self):
        return testlib.Point_GetY(self.p)

    def destroy(self):
        testlib.Point_free(self.p)

    def __str__(self):
        return "%d %d"%(self.GetX(), self.GetY())

    # def __del__(self):
        # testlib.Point_free(self.p)

p = MyPoint(1, 2)
print p
p.destroy()


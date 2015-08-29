#ifndef test_h
#define test_h

#include <iostream>

class Point {
public:
    Point(int x, int y) : d_x(x), d_y(y) {}

    int GetX() { return d_x; }
    int GetY() { return d_y; }

    ~Point() {}

private:
    int d_x, d_y;
};

extern "C" {
    Point *Point_new(int x, int y)
    {
	return new Point(x, y);
    }

    int Point_GetX(Point *p)
    {
	return p->GetX();
    }
    int Point_GetY(Point *p)
    {
	return p->GetY();
    }

    void Point_free(Point *p)
    {
	if (NULL != p) {
	    std::cout << "delete called\n";
	    delete p;
	}
    }
}

#endif

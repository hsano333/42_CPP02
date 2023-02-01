#ifndef POINT_H
#define POINT_H
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point ();
        Point (const float& x, const float& y);
        Point (const  Point &p);
        void operator=(const Point &p);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
        bool isOverFlow(void) const;
        int calcCrossProduct(Point& base, Point& a, Point& b) const;

};

float sign (Point& p1, Point& p2, Point& p3);
bool  PointInTriangle (Point v1, Point v2, Point v3, Point pt);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

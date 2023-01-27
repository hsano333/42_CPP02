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
        Point (const Fixed& x, const Fixed& y);
        Point (const  Point &p);
        void operator=(const Point &p);
        ~Point();


};

#endif

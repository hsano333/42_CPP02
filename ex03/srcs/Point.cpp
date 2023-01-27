#include "Point.hpp"


Point::Point(void) : x(0), y(0)
{
}

Point::Point(const Fixed& rx, const Fixed& ry) : x(rx), y(ry)
{
    //this->x = x;
    //this->y = y;
    //this->x = const_cast <const Fixed &>(x);
    //this->y = const_cast <Fixed &>(y);
}

Point::Point(const Point& p) : x(p.x), y(p.y)
{
    //this->x = p.x;
    //this->x = x;
    //this->y = y;
    //this->x = const_cast <const Fixed&>(p.x);
    //this->y = const_cast <const Fixed&>(p.y);
}

void Point::operator=(const Point &p)
{
    const_cast<Fixed&> (this->x) = p.x;
    const_cast<Fixed&> (this->y) = p.y;
}

Point::~Point()
{
}

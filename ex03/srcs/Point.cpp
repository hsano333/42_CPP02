#include "Point.hpp"
#include <iostream>
#include <string>
#include "Fixed.hpp"


using std::cout;
using std::string;
using std::endl;

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

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}

bool Point::isOverFlow(void) const
{
    if (this->x.isOverFlow() || this->y.isOverFlow())
        return (true);
    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool result = false;
    if (a.isOverFlow() || b.isOverFlow() || c.isOverFlow() || point.isOverFlow())
    {
        cout << "error: overflow" << endl;
        return (false);
    }
    cout << "a:" << a.getX() << ", b:" << b.getX() << ", c:" << c.getX() << "point:" << point.getX() <<  endl;


    return (result);
}
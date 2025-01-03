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

Point::Point(const float& rx, const float& ry) : x(rx), y(ry)
{
}

Point::Point(const Point& p) : x(p.x), y(p.y)
{
}

Point& Point::operator=(const Point &p)
{
    const_cast<Fixed&> (this->x) = p.x;
    const_cast<Fixed&> (this->y) = p.y;
    return (*this);
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

int Point::calcCrossProduct(Point& base, Point& a, Point& b) const
{
    return ((a.x - base.x) * (b.y - base.y) - (b.x - base.x) * (a.y - base.y)).toInt();
}

bool Point::isOverFlow(void) const
{
    if (this->x.isOverFlow() || this->y.isOverFlow())
        return (true);
    return (false);
}

float sign (Point& p1, Point& p2, Point& p3)
{
    return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) \
            - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())).toFloat();
}

bool PointInTriangle (Point v1, Point v2, Point v3, Point pt)
{

    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return (false);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool result = false;
    if (a.isOverFlow() || b.isOverFlow() || c.isOverFlow() || point.isOverFlow())
    {
        cout << "error: overflow" << endl;
        return (false);
    }
    cout << "a:(" << a.getX() << "," <<  a.getY() << ") " <<
            "b:(" << b.getX() << "," <<  b.getY() << ") " <<
            "c:(" << c.getX() << "," <<  c.getY() << ") " <<
            "point:(" << point.getX() << "," <<  point.getY() << ")" << endl;
    result = PointInTriangle(a, b, c, point);
    return (result);
}

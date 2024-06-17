#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::~Point(void)
{}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{}

Point::Point(const Point &from) : _x(from._x), _y(from._y)
{}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return(this->_y);
}

Point& Point::operator=(const Point &from)
{
	if (this != &from)
	{
	(Fixed) this->_x = from.getX();
	(Fixed) this->_y = from.getY();
	}
	return (*this);
}

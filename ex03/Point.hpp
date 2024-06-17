#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp" 

class Point
{
	private:
	const Fixed _x;
	const Fixed _y;
	public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point &from);
	Point& operator=( const Point &from);
	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif
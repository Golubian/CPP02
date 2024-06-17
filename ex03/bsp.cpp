# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed Area = Fixed(0.5f) *((Fixed(-1) * b.getY())*c.getX()+ a.getY()*((Fixed(-1) * b.getX()) + c.getX()) + a.getX()*(b.getY() - c.getY()) + (b.getX()*c.getY()));
	Fixed s = Fixed(1)/(Fixed(2)*Area)*(a.getY()*c.getX() - a.getX()*c.getY() + (c.getY() - a.getY())*point.getX() + (a.getX() - c.getX())*point.getY());
	Fixed t = Fixed(1)/(Fixed(2)*Area)*(a.getX()*b.getY() - a.getY()*b.getX() + (a.getY() - b.getY())*point.getX() + (b.getX() - a.getX())*point.getY());
	return (s > Fixed(0) && t > Fixed(0) && (Fixed(1) - s - t) > Fixed(0));
}

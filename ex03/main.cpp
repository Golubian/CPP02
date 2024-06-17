#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a = Point(0.0f, 0.0f);
	Point b = Point(1.0f, 0.0f);
	Point c = Point(0.0f, 1.0f);
	Point p = Point(0.825f, 0.125f);

	std::cout << bsp(a, b, c, p);
	return 0;
}
#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(double _x, double _y)
{
	x = _x;
	y = _y;
}

bool operator == (const Point _Left, const Point _Right)
{
	if (_Left.x == _Right.x && _Left.y == _Right.y) return true;
	else return false;
}
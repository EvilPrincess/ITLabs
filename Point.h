#pragma once

class Point
{
private:
public:
	double x, y;
	Point();
	Point(double _x, double _y);
};

bool operator == (const Point _Left, const Point _Right);


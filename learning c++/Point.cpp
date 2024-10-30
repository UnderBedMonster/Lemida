#include <iostream>
#include "Point.h"
#include <cmath>

using namespace std;


Point::Point(double x, double y) : x(x), y(y)
{

}

void Point::add(int dx, int dy)
{
	x += dx;
	y += dy;
}

double Point::distance(const Point& p) const
{
	return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

bool Point::compare(Point p)
{
	return (x == p.x && y == p.y);
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}
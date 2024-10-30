#include <iostream>
#include "Dot.h"

using namespace std;

Dot::Dot(double x, double y) : x(x), y(y)
{

}

double Dot::getX() const
{
	return x;
}

double Dot::getY() const
{
	return y;
}

double Dot::distance(const Dot& p) const
{
	int distance = y - x;
	return distance;
}

Dot::~Dot() {
	// TODO Auto-generated destructor stub
}
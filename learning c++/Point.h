#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <string>
#include <sstream>

class Point {
public:
	/**
	 * Constructor and destructor
	 */

	Point() = default;

	Point(const double x, const double y);
	virtual ~Point();

	void add(int dx, int dy);

	/**
	 * Get the x value
	 */
	int getX() { return x; };

	/**
	 * Get the y value
	 */
	int getY() { return y; };

	/**
	 * Return the distance between Points
	 */
	double distance(const Point& p) const;

	bool compare(Point p);

	std::string toString()
	{
		return std::to_string((int)x) + ":" + std::to_string((int)y);
	};

	/**
	 * Output the Point as (x, y) to an output stream
	 */
	friend std::ostream& operator <<(std::ostream&, const Point&);

private:
	double x;
	double y;
};

#endif /* POINT_H_ */ 


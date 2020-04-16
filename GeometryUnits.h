#ifndef GEOMETRY_UNITS
#define GEOMETRY_UNITS

#include <vector>
#include <math.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

using namespace std;

/**
 * Class to represent a simple point
 */
struct Point
{
    /**
     * x coordinate
     */
    double x;

    /**
     * y coordinate
     */
    double y;

    /**
     * Default constructor
     */
    Point();

    /**
     * Parametrized constructor.
     * @param x x coordinate
     * @param y y coordinate
     */
    Point(double x, double y);

    // Operators

    void operator=(const Point &p)
    {
        x = p.x, y = p.y;
    }

    bool operator<(const Point &p)
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }

    Point operator+(const Point &p) const
    {
        Point pt(x + p.x, y + p.y);
        return pt;
    }

    Point operator-(const Point &p) const
    {
        Point pt(x - p.x, y - p.y);
        return pt;
    }

    // Helper functions

    /**
     * Find the cross product of point vector with another point vector.
     * @param p Point with which cross product is to be calculated.
     */
    double crossProduct(const Point &p);

    /**
     * Find the dot product of point vector with another point vector.
     * @param p with which dot product is to be calculated.
     */
    double dotProduct(const Point &p);

    /**
     * Find the distance of the point from the origin
     */
    double dist();
};

/**
 * Checks if three points are in clockwise order or not
 * @param a First point.
 * @param b Second point.
 * @param c Third point.
 */
bool cw(Point &a, Point &b, Point &c);

/**
 * Checks if three points are in counter-clockwise order or not
 * @param a First point.
 * @param b Second point.
 * @param c Third point.
 */
bool ccw(Point &a, Point &b, Point &c);

/**
 * Finds the undigned area of a triangle formed by three points.
 * @param a First point.
 * @param b Second point.
 * @param c Third point.
 */
double area(Point &a, Point &b, Point &c);

/**
 * Checks if the point is inside the given polygon.
 * @param polygon The list of vertices of the polygon in counter clockwise order
 * @param A The point to be tested.
 */
bool isPointInside(vector<Point> polygon, Point A);

#endif
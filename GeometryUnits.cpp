#include "GeometryUnits.h"

Point::Point() {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::crossProduct(const Point &p)
{
    return (x * p.y - y * p.x);
}

double Point::dotProduct(const Point &p)
{
    return (x * p.x + y * p.y);
}

double Point::dist()
{
    return sqrt(x * x + y * y);
}

bool cw(Point &a, Point &b, Point &c)
{
    double A = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return A < 0;
}

bool ccw(Point &a, Point &b, Point &c)
{
    double A = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return A > 0;
}

double area(Point &a, Point &b, Point &c)
{
    double A = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return abs(A);
}

bool isPointInside(vector<Point> polygon, Point A)
{
    int n = polygon.size();
    Point base = polygon[0];
    if (!ccw(base, A, polygon[1]) && !cw(base, A, polygon[1]))
        return true;
    if (!ccw(base, A, polygon[n - 1]) && !cw(base, A, polygon[n - 1]))
        return true;
    if (ccw(base, A, polygon[1]))
        return false;
    if (cw(base, A, polygon[n - 1]))
        return false;
    int first, L = 1, R = n - 1;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (ccw(base, A, polygon[mid]) && (!ccw(base, A, polygon[mid - 1])))
        {
            first = mid;
            break;
        }
        else if (!ccw(base, A, polygon[mid]))
            L = mid + 1;
        else
            R = mid - 1;
    }
    double a1 = area(A, polygon[0], polygon[first]) + area(A, polygon[first], polygon[first - 1]) + area(A, polygon[first - 1], polygon[0]);
    double a2 = area(polygon[0], polygon[first], polygon[first - 1]);
    return (a1 == a2);
}
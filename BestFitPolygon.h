#ifndef BEST_FIT_POLGON
#define BEST_FIT_POLGON

#include "GeometryUnits.h"

using namespace std;

const double PI = acos(-1);

/**
 * Class to find the maximum area of non overlapping discs, with centres contained within a convex polygon.
 */
class MaximumInboundDiscs
{
    int k;
    int d;
    vector<Point> polygon;
    double area = 0;
    double rotationAngle;
    double rotationMatrix[2][2];

    void scalePoints();

    void rotatePoint(Point &a);

    void translatePoint(Point &p1, Point &p2);

    void findBestArea();

public:
    /**
     * Default constructor
     */
    MaximumInboundDiscs();

    /**
     * Parametrized contructor.
     * @param k Number of points to place.
     * @param polygon The list of vertices of the polygon in counter clockwise order
     */
    MaximumInboundDiscs(int numberOfPoints, int dimension, vector<Point> inputPolygon);

    /**
     * Returns the area of the k non-overlapping discs.
     */
    double getArea();
};

#endif
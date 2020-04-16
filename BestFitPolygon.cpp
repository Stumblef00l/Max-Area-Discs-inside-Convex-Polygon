#include "BestFitPolygon.h"

MaximumInboundDiscs::MaximumInboundDiscs() {}

MaximumInboundDiscs::MaximumInboundDiscs(int numberOfPoints, int dimension, vector<Point> inputPolygon) : k(numberOfPoints), polygon(inputPolygon), d(dimension)
{
    rotationAngle = (2 * PI) / (polygon.size());
    rotationMatrix[0][0] = rotationMatrix[1][1] = cos(rotationAngle);
    rotationMatrix[0][1] = -sin(rotationAngle);
    rotationMatrix[1][0] = sin(rotationAngle);
    scalePoints();
    findBestArea();
}

double MaximumInboundDiscs::getArea()
{
    return area;
}

void MaximumInboundDiscs::rotatePoint(Point &a)
{
    double x1, y1;
    x1 = (a.x) * cos(rotationAngle) - (a.y) * sin(rotationAngle);
    y1 = (a.x) * sin(rotationAngle) + (a.y) * cos(rotationAngle);
    a.x = x1;
    a.y = y1;
}

void MaximumInboundDiscs::scalePoints()
{
    for (auto &p : polygon)
    {
        p.x *= d;
        p.y *= d;
    }
}

void MaximumInboundDiscs::translatePoint(Point &p1, Point &p2)
{
    p1.x -= p2.x;
    p1.y -= p2.y;
}

void MaximumInboundDiscs::findBestArea()
{
    int minx = polygon[0].x;
    int miny = polygon[0].y;
    int maxx = polygon[0].x;
    int maxy = polygon[0].y;
    for (auto p : polygon)
    {
        minx = min(minx, p.x);
        maxx = max(maxx, p.x);
        miny = min(miny, p.y);
        maxy = max(maxy, p.y);
    }

    for (int p = minx; p <= maxx; p++)
    {
        for (int q = miny; q <= maxy; q++)
        {
            Point centre = Point(p, q);
            Point reCentre = Point(-p, -q);
            if (!isPointInside(polygon, centre))
                continue;
            for (int r = minx; r <= maxx; r++)
            {
                for (int s = miny; s <= maxy; s++)
                {
                    Point corner = Point(r, s);
                    bool contained = true;
                    MaximumInboundDiscs::translatePoint(corner, centre);
                    for (int i = 1; i <= k; i++)
                    {
                        MaximumInboundDiscs::translatePoint(corner, reCentre);
                        if (!isPointInside(polygon, corner))
                        {
                            contained = false;
                            break;
                        }
                        MaximumInboundDiscs::translatePoint(corner, centre);
                        MaximumInboundDiscs::rotatePoint(corner);
                    }
                    if (contained)
                    {
                        double val = corner.dist();
                        double radius = (val * sin(rotationAngle / 2));
                        radius /= d;
                        area = max(area, k * PI * radius * radius);
                    }
                }
            }
        }
    }
}
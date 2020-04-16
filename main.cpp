#include <iostream>
#include <iomanip>
#include "BestFitPolygon.h"

using namespace std;

int main()
{
    int k;
    vector<Point> listOfPoints;
    int n;
    cout << "Enter the number of circles to be created: ";
    cin >> k;
    int d;
    cout << "Enter the number of dimensions: ";
    cin >> d;
    cout << "Enter the number of vertices of the convex polygon: ";
    cin >> n;
    cout << "Enter the points of the polygon in counter-clockwise order:\n";
    for (int i = 1; i <= n; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        listOfPoints.push_back(p);
    }
    MaximumInboundDiscs ansObject = MaximumInboundDiscs(k, d, listOfPoints);
    cout << std::fixed;
    cout << setprecision(9) << ansObject.getArea();
}
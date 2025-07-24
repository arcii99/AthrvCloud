//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <math.h>

// Structure for 2D points
typedef struct point {
    double x;
    double y;
} Point;

// Function to find area of a triangle given its three vertices
double triangleArea(Point a, Point b, Point c) {
    return fabs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2);
}

// Function to check if a point lies inside a triangle
int pointInsideTriangle(Point p, Point a, Point b, Point c) {
    double areaABC = triangleArea(a, b, c);
    double areaABP = triangleArea(a, b, p);
    double areaACP = triangleArea(a, c, p);
    double areaBCP = triangleArea(b, c, p);
    if ((areaABP+areaACP+areaBCP) == areaABC) {
        return 1;
    } else {
        return 0;
    }
}

// Function to find the distance between two lines
double lineDistance(Point p1, Point q1, Point p2, Point q2) {
    double x1 = p1.x, y1 = p1.y, x2 = q1.x, y2 = q1.y, x3 = p2.x, y3 = p2.y, x4 = q2.x, y4 = q2.y;
    double num = fabs((y2-y1)*x3-(x2-x1)*y3+x2*y1-y2*x1);
    double den = sqrt(pow((y2-y1), 2)+pow((x2-x1), 2));
    return num/den;
}

// Function to find the shortest distance between a point and a line segment
double pointLineSegmentDistance(Point p, Point a, Point b) {
    double d1 = sqrt(pow((p.x-a.x),2)+pow((p.y-a.y),2));
    double d2 = sqrt(pow((p.x-b.x),2)+pow((p.y-b.y),2));
    double d3 = lineDistance(p, a, a, b);
    if (d1 < d2 && d1 < d3) {
        return d1;
    } else if (d2 < d1 && d2 < d3) {
        return d2;
    } else {
        return d3;
    }
}

int main() {
    Point p = {2,3};
    Point a = {1,1};
    Point b = {4,4};
    Point c = {5,2};
    printf("Area of triangle is: %lf\n", triangleArea(a, b, c));
    printf("Is point inside triangle? %d\n", pointInsideTriangle(p, a, b, c));
    printf("Distance between lines is: %lf\n", lineDistance(a, b, c, p));
    printf("Shortest distance between point and line segment is: %lf\n", pointLineSegmentDistance(p, b, c));
    return 0;
}
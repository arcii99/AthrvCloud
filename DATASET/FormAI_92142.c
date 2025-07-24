//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <math.h>

// Define struct for 2D point
typedef struct {
    double x;
    double y;
} Point;

// Calculate the distance between two 2D points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Calculate the area of a triangle given three 2D points
double triangleArea(Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    double s = (ab + bc + ac) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}

// Calculate the slope of a line given two 2D points on the line
double slope(Point a, Point b) {
    return (b.y - a.y) / (b.x - a.x);
}

// Calculate the angle between two lines given the slopes of the lines
double angle(double m1, double m2) {
    return fabs(atan((m2 - m1) / (1 + m1 * m2)));
}

// Check if a 2D point lies within a triangle
int pointInTriangle(Point p, Point a, Point b, Point c) {
    double totalArea = triangleArea(a, b, c);
    double area1 = triangleArea(a, b, p);
    double area2 = triangleArea(b, c, p);
    double area3 = triangleArea(c, a, p);
    return totalArea == area1 + area2 + area3;
}

int main() {
    Point a = {0, 0};
    Point b = {3, 0};
    Point c = {0, 4};
    Point p = {1, 1};
    double m1 = slope(a, b);
    double m2 = slope(b, c);
    double angleBetweenLines = angle(m1, m2);
    int pointInTri = pointInTriangle(p, a, b, c);
    printf("Distance between a and b: %f\n", distance(a, b));
    printf("Distance between b and c: %f\n", distance(b, c));
    printf("Distance between a and c: %f\n", distance(a, c));
    printf("Area of triangle ABC: %f\n", triangleArea(a, b, c));
    printf("Slope of line AB: %f\n", m1);
    printf("Slope of line BC: %f\n", m2);
    printf("Angle between lines AB and BC: %f\n", angleBetweenLines);
    if (pointInTri) {
        printf("Point P is inside triangle ABC\n");
    } else {
        printf("Point P is outside triangle ABC\n");
    }
    return 0;
}
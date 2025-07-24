//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <math.h>

// Point struct representing a cartesian point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double xDiff = p2.x - p1.x;
    double yDiff = p2.y - p1.y;
    return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

// Function to calculate the area of a triangle given 3 points
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Main function
int main() {
    Point p1 = {0,0};
    Point p2 = {3,0};
    Point p3 = {0,4};

    double area = triangleArea(p1, p2, p3);

    printf("Area of triangle with vertices (%.2lf,%.2lf), (%.2lf,%.2lf), and (%.2lf,%.2lf) is %.2lf\n", 
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, area);

    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <math.h>

// Define a Point structure
typedef struct Point {
    double x;
    double y;
} Point;

// Calculate the distance between two points
double distance(Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate the area of a triangle formed by three points
double triangleArea(Point a, Point b, Point c) {
    double sideA = distance(a, b);
    double sideB = distance(b, c);
    double sideC = distance(c, a);
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

int main() {
    // Create three points
    Point a = {0, 0};
    Point b = {3, 0};
    Point c = {0, 4};

    // Calculate the distance between two points
    double distAB = distance(a, b);
    double distBC = distance(b, c);
    double distCA = distance(c, a);
    printf("Distance between A and B is %.2f\n", distAB);
    printf("Distance between B and C is %.2f\n", distBC);
    printf("Distance between C and A is %.2f\n", distCA);

    // Calculate the area of a triangle formed by these three points
    double area = triangleArea(a, b, c);
    printf("Area of triangle ABC is %.2f\n", area);

    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

double distance(Point a, Point b) {
    // calculates distance between 2 points
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

Point centroid(Point a, Point b, Point c) {
    // calculates centroid of 3 points
    Point center;
    center.x = (a.x + b.x + c.x) / 3.0;
    center.y = (a.y + b.y + c.y) / 3.0;
    return center;
}

double area(Point a, Point b, Point c) {
    // calculates area of triangle formed by 3 points
    double side1 = distance(a, b);
    double side2 = distance(b, c);
    double side3 = distance(c, a);
    double p = (side1 + side2 + side3) / 2.0;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

int main() {
    // example usage
    Point a = {0.0, 0.0};
    Point b = {3.0, 0.0};
    Point c = {0.0, 4.0};
    double dist = distance(a, b);
    printf("Distance between a and b: %f\n", dist);
    Point center = centroid(a, b, c);
    printf("Centroid of a, b, c: %f, %f\n", center.x, center.y);
    double a_area = area(a, b, c);
    printf("Area of triangle a, b, c: %f\n", a_area);
    return 0;
}
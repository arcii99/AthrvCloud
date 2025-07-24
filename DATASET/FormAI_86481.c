//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

// defines a point in a 2D plane
typedef struct Point {
    double x;
    double y;
} Point;

// calculates the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// calculates the area of a triangle given three vertices
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p1, p3);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// returns whether or not a point is inside a circle
int pointInCircle(Point p, Point center, double radius) {
    double distanceFromCenter = distance(p, center);
    return (distanceFromCenter <= radius);
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};

    double area = triangleArea(p1, p2, p3);
    printf("The area of the triangle is %.2f\n", area);

    Point center = {1, 1};
    double radius = 2;
    Point p4 = {2, 2};
    Point p5 = {4, 4};
    printf("Point 4 is%s inside the circle.\n", pointInCircle(p4, center, radius) ? "" : " not");
    printf("Point 5 is%s inside the circle.\n", pointInCircle(p5, center, radius) ? "" : " not");

    return 0;
}
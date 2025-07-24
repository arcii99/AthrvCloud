//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point origin;
    double radius;
} Circle;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double angle(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return atan2(dy, dx);
}

Point pointOnCircle(Circle c, double angle) {
    Point p;
    p.x = c.origin.x + c.radius * cos(angle);
    p.y = c.origin.y + c.radius * sin(angle);
    return p;
}

int main() {
    Circle c;
    c.origin.x = 0;
    c.origin.y = 0;
    c.radius = 5;

    double a1 = PI/4;
    double a2 = 3*PI/4;

    Point p1 = pointOnCircle(c, a1);
    Point p2 = pointOnCircle(c, a2);

    double d = distance(p1, p2);

    printf("Distance between points on circle: %f\n", d);
    printf("Expected result: %f\n", 2*c.radius*cos((a2-a1)/2));

    return 0;
}
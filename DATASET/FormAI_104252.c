//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct LineSegment {
    Point p1, p2;
} LineSegment;

typedef struct Triangle {
    Point p1, p2, p3;
} Triangle;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double perimeter(LineSegment ls) {
    return distance(ls.p1, ls.p2);
}

double area(Triangle t) {
    double a = distance(t.p1, t.p2);
    double b = distance(t.p2, t.p3);
    double c = distance(t.p1, t.p3);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};
    LineSegment ls = {p1, p2};
    Triangle t = {p1, p2, p3};

    printf("Perimeter of Line segment: %.2f\n", perimeter(ls));
    printf("Area of Triangle: %.2f\n", area(t));

    return 0;
}
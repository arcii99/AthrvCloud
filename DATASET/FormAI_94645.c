//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>

// Define point struct
typedef struct Point {
    double x;
    double y;
} Point;

// Define line struct
typedef struct Line {
    Point p1;
    Point p2;
} Line;

// Calculate the line slope given two points
double slope(Line l) {
    return (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
}

// Calculate the intersection point of two lines
Point intersection(Line l1, Line l2) {
    double m1 = slope(l1);
    double m2 = slope(l2);
    double b1 = l1.p1.y - m1 * l1.p1.x;
    double b2 = l2.p1.y - m2 * l2.p1.x;
    double x = (b2 - b1) / (m1 - m2);
    double y = m1 * x + b1;
    Point p = {x, y};
    return p;
}

// Calculate the distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate the area of triangle given three points
double triangleArea(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // Example usage
    Point p1 = {0, 0};
    Point p2 = {5, 10};
    Point p3 = {10, 0};
    Line l1 = {p1, p2};
    Line l2 = {p2, p3};
    Point p = intersection(l1, l2);
    double area = triangleArea(p1, p2, p3);
    printf("Intersection point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Triangle area: %.2f\n", area);

    return 0;
}
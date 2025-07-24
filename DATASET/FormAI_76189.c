//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    double a, b, c;
} Line;

Point intersection(Line l1, Line l2);
Line perpendicular_bisector(Point p1, Point p2);
double distance(Point p1, Point p2);

int main() {
    Point p1, p2, p3, mid1, mid2, center;
    Line l1, l2, pb1, pb2;
    double r;

    printf("Enter the coordinates of point 1: ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Enter the coordinates of point 2: ");
    scanf("%lf %lf", &p2.x, &p2.y);
    printf("Enter the coordinates of point 3: ");
    scanf("%lf %lf", &p3.x, &p3.y);

    mid1.x = (p1.x + p2.x) / 2;
    mid1.y = (p1.y + p2.y) / 2;
    mid2.x = (p2.x + p3.x) / 2;
    mid2.y = (p2.y + p3.y) / 2;

    pb1 = perpendicular_bisector(p1, p2);
    pb2 = perpendicular_bisector(p2, p3);

    center = intersection(pb1, pb2);
    r = distance(center, p1);

    printf("The center of the circumcircle is (%.2f, %.2f) and the radius is %.2f\n", center.x, center.y, r);

    return 0;
}

Point intersection(Line l1, Line l2) {
    Point p;
    double det = l1.a * l2.b - l2.a * l1.b;

    p.x = (l2.b * l1.c - l1.b * l2.c) / det;
    p.y = (l1.a * l2.c - l2.a * l1.c) / det;

    return p;
}

Line perpendicular_bisector(Point p1, Point p2) {
    Line l;
    Point mid;

    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;

    l.a = p1.y - p2.y;
    l.b = p2.x - p1.x;
    l.c = -l.a * mid.x - l.b * mid.y;

    return l;
}

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
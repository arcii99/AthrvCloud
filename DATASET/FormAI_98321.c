//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point p1;
    point p2;
} line;

point get_intersection(line l1, line l2) {
    double x1 = l1.p1.x, y1 = l1.p1.y;
    double x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y;
    double x4 = l2.p2.x, y4 = l2.p2.y;
    double px = ((x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3*y4 - y3*x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    double py = ((x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3*y4 - y3*x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    point p = { px, py };
    return p;
}

int main() {
    line l1 = { {0, 0}, {1, 1} };
    line l2 = { {0, 1}, {1, 0} };
    point p = get_intersection(l1, l2);
    printf("Intersection point: (%lf, %lf)\n", p.x, p.y);
    return 0;
}
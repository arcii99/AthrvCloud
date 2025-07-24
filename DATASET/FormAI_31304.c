//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

struct Point2D {
    double x;
    double y;
};

struct Line2D {
    struct Point2D p1;
    struct Point2D p2;
};

double distance(struct Point2D p1, struct Point2D p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

struct Point2D midpoint(struct Point2D p1, struct Point2D p2) {
    struct Point2D m;
    m.x = (p1.x + p2.x) / 2.0;
    m.y = (p1.y + p2.y) / 2.0;
    return m;
}

struct Line2D perpendicular_bisector(struct Point2D p1, struct Point2D p2) {
    struct Point2D m = midpoint(p1, p2);
    struct Line2D l;
    l.p1 = m;
    l.p2.x = m.x + (p2.y - p1.y);
    l.p2.y = m.y + (p1.x - p2.x);
    return l;
}

struct Point2D intersection(struct Line2D l1, struct Line2D l2) {
    double a1 = l1.p2.y - l1.p1.y;
    double b1 = l1.p1.x - l1.p2.x;
    double c1 = a1*l1.p1.x + b1*l1.p1.y;
    double a2 = l2.p2.y - l2.p1.y;
    double b2 = l2.p1.x - l2.p2.x;
    double c2 = a2*l2.p1.x + b2*l2.p1.y;
    double det = a1*b2 - a2*b1;
    struct Point2D p;
    if (det == 0) {
        p.x = NAN;
        p.y = NAN;
    } else {
        p.x = (b2*c1 - b1*c2) / det;
        p.y = (a1*c2 - a2*c1) / det;
    }
    return p;
}

int main() {
    struct Point2D p1 = {0.0, 0.0};
    struct Point2D p2 = {1.0, 1.0};
    struct Point2D p3 = {0.0, 1.0};

    struct Line2D l1 = perpendicular_bisector(p1, p2);
    struct Line2D l2 = perpendicular_bisector(p1, p3);

    struct Point2D i = intersection(l1, l2);

    printf("Intersection point: (%f, %f)\n", i.x, i.y);

    return 0;
}
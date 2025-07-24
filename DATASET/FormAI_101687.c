//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x, y;
};

struct Line {
    double m, b;
};

struct Circle {
    struct Point center;
    double radius;
};

double getDistance(struct Point p1, struct Point p2) {
    double xDiff = p2.x - p1.x;
    double yDiff = p2.y - p1.y;
    double distance = sqrt((xDiff * xDiff) + (yDiff * yDiff));
    return distance;
}

struct Line getPerpendicularBisector(struct Point p1, struct Point p2) {
    double midpointX = (p1.x + p2.x) / 2;
    double midpointY = (p1.y + p2.y) / 2;
    double slope = (p1.y - p2.y) / (p1.x - p2.x);
    double perpSlope = -1 / slope;
    double yIntercept = midpointY - (perpSlope * midpointX);
    struct Line perpBisector = { perpSlope, yIntercept };
    return perpBisector;
}

int intersectionPoint(struct Line l1, struct Line l2, struct Point *intersection) {
    if (l1.m == l2.m) {
        return 0;
    }

    double x = (l2.b - l1.b) / (l1.m - l2.m);
    double y = l1.m * x + l1.b;
    intersection->x = x;
    intersection->y = y;
    return 1;
}

int intersectionCircleLine(struct Circle circle, struct Line line, struct Point *intersection1, struct Point *intersection2) {
    double m = line.m;
    double b = line.b;
    double xc = circle.center.x;
    double yc = circle.center.y;
    double r = circle.radius;

    double A = 1 + (m * m);
    double B = (-2 * xc) + (2 * m * b) - (2 * yc * m);
    double C = (xc * xc) + (b * b) + (yc * yc) - (2 * b * yc) - (r * r);

    // Quadratic formula
    double delta = (B * B) - (4 * A * C);
    if (delta < 0) {
        return 0;
    }
    double sqrtDelta = sqrt(delta);
    double x1 = (-B + sqrtDelta) / (2 * A);
    double x2 = (-B - sqrtDelta) / (2 * A);
    double y1 = m * x1 + b;
    double y2 = m * x2 + b;

    intersection1->x = x1;
    intersection1->y = y1;
    intersection2->x = x2;
    intersection2->y = y2;
    return 1;
}

int main() {
    struct Point p1 = { 1, 2 };
    struct Point p2 = { 4, 6 };
    double distance = getDistance(p1, p2);
    printf("Distance: %lf\n", distance);

    struct Line perpBisector = getPerpendicularBisector(p1, p2);
    printf("Perpendicular Bisector: y = %lfx + %lf\n", perpBisector.m, perpBisector.b);

    struct Point intersection;
    struct Line l1 = { 1, 0 };
    struct Line l2 = { -1, 3 };
    if (intersectionPoint(l1, l2, &intersection)) {
        printf("Intersection Point: (%lf, %lf)\n", intersection.x, intersection.y);
    }
    else {
        printf("Lines are parallel\n");
    }

    struct Circle circle = { { 0, 0 }, 5 };
    struct Line line = { 1, 0 };
    struct Point intersection1, intersection2;
    if (intersectionCircleLine(circle, line, &intersection1, &intersection2)) {
        printf("Intersection Points: (%lf, %lf) and (%lf, %lf)\n", intersection1.x, intersection1.y, intersection2.x, intersection2.y);
    }
    else {
        printf("Line does not intersect circle\n");
    }

    return 0;
}
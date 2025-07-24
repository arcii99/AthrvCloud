//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the intersection point of two lines in 2D space */

typedef struct point {
    double x;
    double y;
} Point;

typedef struct line {
    Point p1;
    Point p2;
} Line;

/* Finds the intersection point of two lines */
Point intersection(Line l1, Line l2) {
    double x1 = l1.p1.x, y1 = l1.p1.y;
    double x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y;
    double x4 = l2.p2.x, y4 = l2.p2.y;

    double det = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);

    if (det == 0)
        return (Point){INFINITY, INFINITY};

    double x = ((x1*y2-y1*x2)*(x3-x4) - (x1-x2)*(x3*y4-y3*x4))/det;
    double y = ((x1*y2-y1*x2)*(y3-y4) - (y1-y2)*(x3*y4-y3*x4))/det;

    return (Point){x,y};
}

int main() {
    /* Example usage */
    Line l1 = {{0,0}, {2,2}};
    Line l2 = {{0,2}, {2,0}};

    Point intersection_point = intersection(l1, l2);

    printf("Intersection point: (%.2f, %.2f)\n", intersection_point.x, intersection_point.y);

    return 0;
}
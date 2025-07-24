//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
/* This program calculates the intersection point of two lines in a 2D cartesian coordinate system using the determinants method. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    double a, b, c;
} Line;

double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

Point intersection(Line l1, Line l2) {
    Point p;

    double det = determinant(l1.a, l1.b, l2.a, l2.b);
    if (det == 0) {
        printf("Error: lines are parallel or coincident\n");
        exit(1);
    }

    double det_x = determinant(-l1.c, l1.b, -l2.c, l2.b);
    double det_y = determinant(l1.a, -l1.c, l2.a, -l2.c);

    p.x = det_x / det;
    p.y = det_y / det;

    return p;
}

int main() {
    Line l1 = {2, -1, 5};
    Line l2 = {4, 3, 1};

    Point intersection_point = intersection(l1, l2);

    printf("Intersection point: (%lf, %lf)\n", intersection_point.x, intersection_point.y);

    return 0;
}
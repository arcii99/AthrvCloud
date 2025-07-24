//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Point structure
struct Point {
    double x, y;
};

// Define Line structure
struct Line {
    struct Point *p1, *p2;
};

// Define Triangle structure
struct Triangle {
    struct Point *p1, *p2, *p3;
};

// Calculate distance between two points
double distance(struct Point *p1, struct Point *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

// Check if a point is inside a triangle
int isInsideTriangle(struct Point *p, struct Triangle *t) {
    double area = (
        (t->p2->x - t->p1->x)*(t->p3->y - t->p1->y) -
        (t->p3->x - t->p1->x)*(t->p2->y - t->p1->y)
    ) / 2.0;
    double b1 = (
        (p->x - t->p2->x)*(t->p3->y - t->p2->y) -
        (t->p3->x - t->p2->x)*(p->y - t->p2->y)
    ) / (2.0 * area);
    double b2 = (
        (p->x - t->p3->x)*(t->p1->y - t->p3->y) -
        (t->p1->x - t->p3->x)*(p->y - t->p3->y)
    ) / (2.0 * area);
    double b3 = (
        (p->x - t->p1->x)*(t->p2->y - t->p1->y) -
        (t->p2->x - t->p1->x)*(p->y - t->p1->y)
    ) / (2.0 * area);
    if (b1 >= 0 && b2 >= 0 && b3 >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Define some points, lines and triangles
    struct Point p1 = {0, 0};
    struct Point p2 = {0, 3};
    struct Point p3 = {4, 0};
    struct Point p4 = {4, 3};
    struct Point p5 = {1, 1};
    struct Point p6 = {2, 2};
    struct Line l1 = {&p1, &p3};
    struct Line l2 = {&p2, &p4};
    struct Line l3 = {&p1, &p2};
    struct Line l4 = {&p3, &p4};
    struct Triangle t1 = {&p1, &p2, &p3};
    struct Triangle t2 = {&p2, &p4, &p3};

    // Test distance function
    printf("Distance between p1 and p2 is: %f\n", distance(&p1, &p2));

    // Test isInsideTriangle function
    printf("p5 is inside t1: %d\n", isInsideTriangle(&p5, &t1));
    printf("p6 is inside t2: %d\n", isInsideTriangle(&p6, &t2));

    return 0;
}
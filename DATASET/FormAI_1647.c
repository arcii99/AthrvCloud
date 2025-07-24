//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct rect {
    point p;
    double width;
    double height;
} rect;

// function to calculate the distance between two points
double distance(point p1, point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// function to check if two rectangles intersect
int intersect(rect r1, rect r2) {
    if (r1.p.x + r1.width < r2.p.x || r2.p.x + r2.width < r1.p.x)
        return 0;
    if (r1.p.y + r1.height < r2.p.y || r2.p.y + r2.height < r1.p.y)
        return 0;
    return 1;
}

int main() {
    point p1 = {2, 3};
    point p2 = {5, 6};
    rect r1 = {p1, 4, 2};
    rect r2 = {{4, 4}, 3, 4};

    printf("Distance between p1 and p2: %lf\n", distance(p1, p2));

    if (intersect(r1, r2))
        printf("Rectangles intersect\n");
    else
        printf("Rectangles do not intersect\n");

    return 0;
}
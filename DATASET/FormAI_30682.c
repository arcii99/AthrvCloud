//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>

/* A geometric algorithm that finds the intersection of a ray cast from a point with a line segment. */

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} LineSegment;

typedef struct {
    Point origin;
    Point direction;
} Ray;

Point getIntersection(Ray r, LineSegment ls) {
    Point res;
    
    double denominator = (r.direction.x * (ls.p1.y - ls.p2.y)) - ((ls.p1.x - ls.p2.x) * r.direction.y);
    
    if (denominator == 0) {
        printf("The ray and the line segment do not intersect.\n");
        return res;
    }
    
    double t = (((ls.p1.x - r.origin.x) * (ls.p1.y - ls.p2.y)) - ((ls.p1.y - r.origin.y) * (ls.p1.x - ls.p2.x))) / denominator;
    
    if (t <= 0 || t >= 1) {
        printf("The intersection point is outside of the line segment.\n");
        return res;
    }
    
    res.x = r.origin.x + (t * r.direction.x);
    res.y = r.origin.y + (t * r.direction.y);
    
    return res;
}

int main() {
    Point p1 = {1, 2};
    Point p2 = {4, 5};
    LineSegment ls = {p1, p2};
    Point origin = {2, 1};
    Point direction = {1, 1};
    Ray r = {origin, direction};
    
    Point intersection = getIntersection(r, ls);
    
    printf("The intersection point is: (%.2f, %.2f)\n", intersection.x, intersection.y);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double area(Point a, Point b, Point c) {
    double s = (distance(a,b) + distance(b,c) + distance(a,c))/2.0;
    return sqrt(s*(s-distance(a,b))*(s-distance(b,c))*(s-distance(a,c)));
}

int orientation(Point a, Point b, Point c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x -a.x) * (c.y - b.y);
    if(val == 0.0) return 0;
    return (val > 0) ? 1 : 2;
}

void findConvexHull(Point points[], int numPoints) {
    int hull[numPoints];
    int hullSize = 0;

    int leftmost = 0;
    for(int i = 1; i < numPoints; i++) {
        if(points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    int curr = leftmost;
    do {
        hull[hullSize++] = curr;
        int next = (curr+1) % numPoints;
        for(int i = 0; i < numPoints; i++) {
            if(orientation(points[curr], points[i], points[next]) == 2) {
                next = i;
            }
        }
        curr = next;
    } while(curr != leftmost);

    printf("Convex Hull: \n");
    for(int i = 0; i < hullSize; i++) {
        printf("(%lf, %lf)\n", points[hull[i]].x, points[hull[i]].y);
    }
}

int main() {
    Point a = {0, 0};
    Point b = {1, 0};
    Point c = {0, 1};
    Point d = {1, 1};
    Point e = {2, 2};

    printf("Area of Triangle (a,b,c): %lf\n", area(a,b,c));
    printf("Distance between a and d: %lf\n", distance(a,d));
    printf("Orientation of (a,b,c): %d\n", orientation(a,b,c));
    printf("Orientation of (a,c,b): %d\n", orientation(a,c,b));

    Point points[] = {a, b, c, d, e};
    findConvexHull(points, 5);

    return 0;
}
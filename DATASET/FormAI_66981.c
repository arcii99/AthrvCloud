//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
struct Point {
    int x, y;
};
 
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) {
        return 0;  // colinear
    } else if (val > 0) {
        return 1;  // clockwise orientation
    } else {
        return 2;  // counterclockwise orientation
    }
}
 
void convexHull(struct Point points[], int n) {
    if (n < 3) {
        return;
    }
 
    int hull[n], hullSize = 0;
 
    // Find leftmost point
    int leftMost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftMost].x) {
            leftMost = i;
        }
    }
 
    int p = leftMost, q;
    do {
        hull[hullSize++] = p;
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != leftMost);
 
    // Print convex hull
    printf("Convex hull:\n");
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", points[hull[i]].x, points[hull[i]].y);
    }
}
 
int main() {
    struct Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
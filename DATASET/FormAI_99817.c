//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

int cmpfunc(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    if (p1->x == p2->x) return (p1->y - p2->y);
    return (p1->x - p2->x);
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(Point points[], int n) {
    if (n < 3) return;
    int hull[n];
    int l = 0, i;
    for (i = 0; i < n; i++) {
        if (points[i].x < points[l].x) l = i;
    }
    int p = l, q;
    do {
        hull[i++] = p;
        q = (p + 1) % n;
        for (int j = 0; j < n; j++) {
            if (orientation(points[p], points[j], points[q]) == 2) {
                q = j;
            }
        }
        p = q;
    } while (p != l);
    for (i = 0; i < n; i++) {
        printf("Convex hull point %d: (%.2lf, %.2lf)\n", i, points[hull[i]].x, points[hull[i]].y);
    }
}

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    qsort(points, n, sizeof(Point), cmpfunc);
    convexHull(points, n);
    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

struct point {
    double x, y;
};

double distance(struct point p1, struct point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int orientation(struct point p, struct point q, struct point r) {
    double val = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  
    return (val > 0) ? 1 : 2;  
}

void convexHull(struct point points[], int n) {
    if (n < 3) return;

    int hull[MAX_POINTS], hull_size = 0;

    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) leftmost = i;
    }

    int p = leftmost, q;
    do {
        hull[hull_size++] = p;

        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;

    } while (p != leftmost);

    for (int i = 0; i < hull_size; i++) {
        printf("(%lf, %lf)\n", points[hull[i]].x, points[hull[i]].y);
    }
}

int main() {
    struct point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
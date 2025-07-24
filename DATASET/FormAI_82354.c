//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int orientation(Point a, Point b, Point c) {
    double cross = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    if (cross > 0) return 1; // counter-clockwise
    if (cross < 0) return -1; // clockwise
    return 0; // collinear
}

int cmp_points(const void *p1, const void *p2) {
    Point *a = (Point*)p1, *b = (Point*)p2;
    return (a->x > b->x) - (a->x < b->x);
}

void convex_hull(Point *points, int n, Point *ch, int *ch_size) {
    qsort(points, n, sizeof(Point), cmp_points);
    *ch_size = 0;
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[min_idx].y ||
            (points[i].y == points[min_idx].y && points[i].x < points[min_idx].x)) {
            min_idx = i;
        }
    }
    ch[(*ch_size)++] = points[min_idx];
    int current = min_idx;
    do {
        int next = (current+1)%n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[current], points[i], points[next]) == -1) {
                next = i;
            }
        }
        ch[(*ch_size)++] = points[next];
        current = next;
    } while (current != min_idx);
}

int main() {
    Point points[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {0.5, 0.5}};
    Point ch[5];
    int ch_size;
    convex_hull(points, 5, ch, &ch_size);
    printf("Convex hull:\n");
    for (int i = 0; i < ch_size; i++) {
        printf("(%g, %g)\n", ch[i].x, ch[i].y);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

struct Point {
    double x, y;
};

int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;
    if (p1->y < p2->y || (p1->y == p2->y && p1->x < p2->x))
        return -1;
    else if (p1->y > p2->y || (p1->y == p2->y && p1->x > p2->x))
        return 1;
    return 0;
}

double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
}

int orientation(struct Point p, struct Point q, struct Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val > 0) ? 1 : ((val < 0) ? -1 : 0);
}

void swap(struct Point *p1, struct Point *p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void print_hull(struct Point points[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("(%g, %g)\n", points[i].x, points[i].y);
}

void graham_scan(struct Point points[], int n, struct Point hull[]) {
    int i, j, m = 0, t;
    struct Point p0 = points[0];

    for (i = 1; i < n; i++)
        if (points[i].y < p0.y || (points[i].y == p0.y && points[i].x < p0.x))
            p0 = points[i];

    swap(&points[0], &p0);

    for (i = 1; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int or = orientation(points[0], points[i], points[j]);
            if (or < 0 || (or == 0 && distance(points[0], points[i]) > distance(points[0], points[j])))
                swap(&points[i], &points[j]);
        }
    }

    hull[m++] = points[0];
    hull[m++] = points[1];
    hull[m++] = points[2];
    for (i = 3; i < n; i++) {
        while (orientation(hull[m - 2], hull[m - 1], points[i]) <= 0) {
            m--;
            if (m == 2)
                break;
        }
        hull[m++] = points[i];
    }

    t = hull[0].x * (hull[1].y - hull[m - 1].y) + hull[m - 1].x * (hull[0].y - hull[1].y) + hull[1].x * (hull[m - 1].y - hull[0].y);
    if (t < 0)
        for (i = 0; i < m / 2; i++)
            swap(&hull[i], &hull[m - i - 1]);
}

int main() {
    struct Point points[MAX_POINTS], hull[MAX_POINTS];
    int n, i;

    printf("Enter number of points:");
    scanf("%d", &n);

    printf("Enter the points (x, y):\n");
    for (i = 0; i < n; i++)
        scanf("%lf%lf", &points[i].x, &points[i].y);

    qsort(&points[0], n, sizeof(struct Point), compare);

    graham_scan(points, n, hull);

    printf("\nConvex hull is:\n");
    print_hull(hull, n);

    return 0;
}
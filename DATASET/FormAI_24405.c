//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

int compare_points(const Point *p1, const Point *p2) {
    if (p1->x == p2->x) {
        return (p1->y > p2->y) - (p1->y < p2->y);
    }
    return (p1->x > p2->x) - (p1->x < p2->x);
}

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int is_same_line(Point p1, Point p2, Point p3) {
    return (p3.y - p1.y) * (p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x);
}

void find_hull(Point points[], int npoints, Point hull[], int *n) {
    int i, j;

    qsort(points, npoints, sizeof(Point), compare_points);

    for (i = 0; i < npoints; i++) {
        while (*n >= 2 &&
            (hull[*n-1].y - hull[*n-2].y) * (points[i].x - hull[*n-2].x) <=
            (points[i].y - hull[*n-2].y) * (hull[*n-1].x - hull[*n-2].x)) {
            (*n)--;
        }
        hull[*n] = points[i];
        (*n)++;
    }

    j = *n - 2;
    for (i = npoints-2; i >= 0; i--) {
        while (*n >= j+2 &&
            (hull[*n-1].y - hull[*n-2].y) * (points[i].x - hull[*n-2].x) <=
            (points[i].y - hull[*n-2].y) * (hull[*n-1].x - hull[*n-2].x)) {
            (*n)--;
        }
        hull[*n] = points[i];
        (*n)++;
    }
}

int main(void) {
    int npoints, i, j, k, n;
    Point points[MAX_POINTS];
    Point hull[MAX_POINTS];
    double area = 0;

    scanf("%d", &npoints);
    for (i = 0; i < npoints; i++) {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }

    find_hull(points, npoints, hull, &n);

    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        k = (i + 2) % n;
        area += hull[i].x * hull[j].y +
            hull[j].x * hull[k].y +
            hull[k].x * hull[i].y -
            hull[i].x * hull[k].y -
            hull[j].x * hull[i].y -
            hull[k].x * hull[j].y;
    }

    area /= 2;
    printf("%.2lf", fabs(area));

    return 0;
}
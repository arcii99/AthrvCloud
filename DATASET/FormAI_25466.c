//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double polygonArea(Point *points, int nPoints) {
    double area = 0.0;
    int j;
    for (int i = 0; i < nPoints; i++) {
        j = (i + 1) % nPoints;
        area += points[i].x*points[j].y;
        area -= points[i].y*points[j].x;
    }
    area /= 2.0;
    return (area >= 0.0) ? area : -area;
}

void convexHull(Point *points, int nPoints, Point *hull, int *nHull) {
    if (nPoints < 3) {
        *nHull = 0;
        return;
    }

    int hullPoints[nPoints];
    for (int i = 0; i < nPoints; i++) {
        hullPoints[i] = -1;
    }

    int k = 0;
    for (int i = 0; i < nPoints; i++) {
        if ((hullPoints[k] == -1) || (points[i].x < points[hullPoints[k]].x)) {
            k++;
            hullPoints[k] = i;
        }
    }

    int upperHull[MAX_POINTS];
    int upperN = 0;
    upperHull[upperN++] = hullPoints[0];
    upperHull[upperN++] = hullPoints[1];
    for (int i = 2; i <= k; i++) {
        while ((upperN >= 2)
                && ((points[upperHull[upperN - 2]].x - points[upperHull[upperN - 1]].x)*(points[hullPoints[i]].y - points[upperHull[upperN - 1]].y)
                    >= (points[hullPoints[i]].x - points[upperHull[upperN - 1]].x)*(points[upperHull[upperN - 2]].y - points[upperHull[upperN - 1]].y))) {
            upperN--;
        }
        upperHull[upperN++] = hullPoints[i];
    }

    int lowerHull[MAX_POINTS];
    int lowerN = 0;
    lowerHull[lowerN++] = hullPoints[k];
    lowerHull[lowerN++] = hullPoints[k + 1];
    for (int i = k + 2; i < nPoints; i++) {
        while ((lowerN >= 2)
                && ((points[lowerHull[lowerN - 2]].x - points[lowerHull[lowerN - 1]].x)*(points[hullPoints[i]].y - points[lowerHull[lowerN - 1]].y)
                    >= (points[hullPoints[i]].x - points[lowerHull[lowerN - 1]].x)*(points[lowerHull[lowerN - 2]].y - points[lowerHull[lowerN - 1]].y))) {
            lowerN--;
        }
        lowerHull[lowerN++] = hullPoints[i];
    }

    int n = 0;
    for (int i = 0; i < upperN; i++) {
        hull[n++] = points[upperHull[i]];
    }

    for (int i = lowerN - 2; i > 0; i--) {
        hull[n++] = points[lowerHull[i]];
    }

    *nHull = n;
}

int main() {
    int nPoints = 7;
    Point points[MAX_POINTS] = { {0, 0}, {1, 1}, {2, 2}, {2, 0}, {3, 1}, {3, 3}, {1, 2} };
    Point hull[MAX_POINTS];
    int nHull;

    convexHull(points, nPoints, hull, &nHull);

    printf("Convex hull points:\n");
    for (int i = 0; i < nHull; i++) {
        printf("(%g, %g)\n", hull[i].x, hull[i].y);
    }

    double area = polygonArea(hull, nHull);
    printf("Convex hull area: %g\n", area);

    return 0;
}
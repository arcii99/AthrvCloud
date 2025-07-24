//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calcDist(struct Point p1, struct Point p2) {
    double xdiff = p1.x - p2.x;
    double ydiff = p1.y - p2.y;
    return sqrt(xdiff * xdiff + ydiff * ydiff);
}

double calcTriangleArea(struct Point p1, struct Point p2, struct Point p3) {
    double a = calcDist(p1, p2);
    double b = calcDist(p1, p3);
    double c = calcDist(p2, p3);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int isConvex(struct Point polygon[], int n) {
    int i, j, k;
    int flag = 0;
    double area;
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        k = (i + 2) % n;
        area = (polygon[j].x - polygon[i].x)*(polygon[k].y - polygon[j].y) -
               (polygon[j].y - polygon[i].y)*(polygon[k].x - polygon[j].x);
        if (area < 0) {
            flag |= 1;
        } else if (area > 0) {
            flag |= 2;
        }
        if (flag == 3) {
            return 0;
        }
    }
    if (flag != 0) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char* argv[]) {
    struct Point p1 = {0, 0};
    struct Point p2 = {1, 0};
    struct Point p3 = {0, 1};
    double dist = calcDist(p1, p2);
    double area = calcTriangleArea(p1, p2, p3);
    printf("Distance between points: %.2f\n", dist);
    printf("Area of triangle: %.2f\n", area);

    int n = 4;
    struct Point polygon[] = {
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 0}
    };
    int convex = isConvex(polygon, n);
    if (convex == 1) {
        printf("Polygon is convex.\n");
    } else if (convex == 0) {
        printf("Polygon is non-convex.\n");
    } else {
        printf("Invalid polygon.\n");
    }

    return 0;
}
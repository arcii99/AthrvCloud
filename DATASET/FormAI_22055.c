//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

struct Point {
    double x, y;
};
typedef struct Point point;

double distance(point p1, point p2) {
    double dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

double cross_product(point a, point b, point c) {
    double result = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return result;
}

point find_midpoint(point p1, point p2) {
    point midpoint;
    midpoint.x = (p1.x + p2.x) / 2;
    midpoint.y = (p1.y + p2.y) / 2;
    return midpoint;
}

double perimeter(point polygon[], int n) {
    double peri = 0;
    for (int i=0; i<n-1; i++) {
        peri += distance(polygon[i], polygon[i+1]);
    }
    peri += distance(polygon[0], polygon[n-1]);
    return peri;
}

double area(point polygon[], int n) {
    double area = 0;
    for (int i=0; i<n-1; i++) {
        area += (polygon[i].x * polygon[i+1].y) - (polygon[i].y * polygon[i+1].x);
    }
    area += (polygon[n-1].x * polygon[0].y) - (polygon[n-1].y * polygon[0].x);
    area /= 2;
    return fabs(area);
}

int is_convex(point polygon[], int n) {
    int sign = 0;
    for (int i=0; i<n; i++) {
        double cross = cross_product(polygon[i], polygon[(i+1)%n], polygon[(i+2)%n]);
        if (cross != 0) {
            if (sign == 0) {
                sign = cross > 0 ? 1 : -1;
            } else if ((cross > 0) ^ (sign > 0)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &n);
    point polygon[n];
    printf("Enter the %d points of the polygon:\n", n);
    for (int i=0; i<n; i++) {
        scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
    }
    double p = perimeter(polygon, n);
    double a = area(polygon, n);
    point mid = find_midpoint(polygon[0], polygon[n-1]);
    int convex = is_convex(polygon, n);
    printf("Perimeter: %lf\n", p);
    printf("Area: %lf\n", a);
    printf("Midpoint: (%lf, %lf)\n", mid.x, mid.y);
    printf("Convex: %d\n", convex);
    return 0;
}
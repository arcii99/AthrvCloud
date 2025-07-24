//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include<stdio.h>
#include<math.h>

typedef struct point {
    double x, y;
} point;

double distance(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx*dx + dy*dy);
}

double area_triangle(point a, point b, point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);
    double s = (ab + bc + ca) / 2;

    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

double area_polygon(int n, point p[]) {
    double area = 0;

    for (int i = 1; i < n-1; i++) {
        area += area_triangle(p[0], p[i], p[i+1]);
    }

    return area;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    point p[n];
    printf("Enter the points in clockwise or counterclockwise order:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &p[i].x);
        printf("y[%d] = ", i);
        scanf("%lf", &p[i].y);
    }

    double area = area_polygon(n, p);
    printf("Area inside the polygon = %lf\n", area);

    return 0;
}
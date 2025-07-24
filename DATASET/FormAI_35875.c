//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double shoelace(Point *polygon, int n) {
    double area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += polygon[i].x * polygon[i + 1].y - polygon[i + 1].x * polygon[i].y;
    }
    area += polygon[n - 1].x * polygon[0].y - polygon[0].x * polygon[n - 1].y;
    return 0.5 * fabs(area);
}

int main() {
    // Example polygon with 4 vertices
    Point polygon[4] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    int n = sizeof(polygon) / sizeof(Point);

    double area = shoelace(polygon, n);
    printf("The area of the polygon is %.2f\n", area);

    return 0;
}
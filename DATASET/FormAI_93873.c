//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

// This program calculates the area of a convex polygon using the Shoelace formula

typedef struct {
    double x;
    double y;
} point;

double shoelace_formula(point *polygon, int num_points) {
    double area = 0;
    int j = num_points - 1;
    for (int i = 0; i < num_points; i++) {
        area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);
        j = i;
    }
    return fabs(area / 2);
}

int main() {
    // Example polygon: a square with side length 2
    point polygon[4] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int num_points = 4;
    double area = shoelace_formula(polygon, num_points);
    printf("Area of polygon: %f\n", area);
    return 0;
}
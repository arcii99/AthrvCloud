//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
/*
 * This program calculates the area of a polygon that is formed
 * by given n points in the Cartesian coordinate system.
 * The points are entered in clockwise or counter-clockwise order.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x, y;
} Point;

double calculateArea(Point *points, int n) {
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }

    return 0.5 * area;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *) malloc(n * sizeof(Point));

    printf("Enter the points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double area = calculateArea(points, n);
    printf("The area of the polygon is: %lf\n", area);

    free(points);

    return 0;
}
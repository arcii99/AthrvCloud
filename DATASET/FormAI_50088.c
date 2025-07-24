//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>

/* This program calculates the area of a triangle using the coordinates of its vertices */
/* I am grateful for the power of geometric algorithms in computer science */

struct Point {
    double x;
    double y;
};

typedef struct Point Point;

double area_triangle(Point a, Point b, Point c) {
    /* Using the Shoelace formula */
    double area = 0.5 * ((a.x*b.y + b.x*c.y + c.x*a.y) - (a.x*c.y + b.x*a.y + c.x*b.y));
    return area;
}

int main() {
    printf("Welcome to the triangle area calculator!\n");

    Point vertices[3];

    printf("Please enter the coordinates of the first vertex (format: x y): ");
    scanf("%lf %lf", &vertices[0].x, &vertices[0].y);

    printf("Please enter the coordinates of the second vertex (format: x y): ");
    scanf("%lf %lf", &vertices[1].x, &vertices[1].y);

    printf("Please enter the coordinates of the third vertex (format: x y): ");
    scanf("%lf %lf", &vertices[2].x, &vertices[2].y);

    double area = area_triangle(vertices[0], vertices[1], vertices[2]);

    printf("\nThe area of a triangle with vertices (%.2lf,%.2lf), (%.2lf,%.2lf), and (%.2lf,%.2lf) is %.2lf square units.\n",
            vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y, area);

    return 0;
}
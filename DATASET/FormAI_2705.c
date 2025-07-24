//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to hold the coordinates of a point in 2D space
typedef struct point {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points in 2D space
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Create three points in 2D space
    Point p1, p2, p3;
    p1.x = 0; p1.y = 0;
    p2.x = 1; p2.y = 0;
    p3.x = 0; p3.y = 1;

    // Calculate the length of each side of the triangle formed by the three points
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);

    // Calculate the semiperimeter of the triangle
    double s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    // Print out the coordinates and lengths of each side of the triangle
    printf("Point 1: (%f, %f)\n", p1.x, p1.y);
    printf("Point 2: (%f, %f)\n", p2.x, p2.y);
    printf("Point 3: (%f, %f)\n", p3.x, p3.y);
    printf("Side a: %f\n", a);
    printf("Side b: %f\n", b);
    printf("Side c: %f\n", c);

    // Print out the area of the triangle
    printf("Area of triangle: %f\n", area);

    return 0;
}
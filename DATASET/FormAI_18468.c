//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: systematic
/*
 * Program to calculate the area of a triangle using three points in 2D coordinate space
 */

#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    struct Point p1, p2, p3;
    printf("Enter the coordinates of the first point (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Enter the coordinates of the second point (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);
    printf("Enter the coordinates of the third point (x y): ");
    scanf("%lf %lf", &p3.x, &p3.y);

    double a = distance(p1, p2);
    double b = distance(p1, p3);
    double c = distance(p2, p3);

    // Use Heron's formula to calculate the area of the triangle
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("Area of the triangle is: %lf\n", area);
    return 0;
}
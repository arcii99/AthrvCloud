//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>

// A function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// A function to calculate the area of a triangle
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // Let's define three points on the Cartesian plane
    double x1 = 0, y1 = 0;
    double x2 = 4, y2 = 0;
    double x3 = 2, y3 = 3;

    // Let's calculate the distance between points 1 and 2
    double d12 = distance(x1, y1, x2, y2);
    printf("The distance between points 1 and 2 is %f\n", d12);

    // Let's calculate the area of the triangle formed by the three points
    double a123 = area(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle formed by points 1, 2 and 3 is %f\n", a123);

    // Let's calculate the centroid of the triangle formed by the three points
    double xc = (x1 + x2 + x3) / 3;
    double yc = (y1 + y2 + y3) / 3;
    printf("The centroid of the triangle formed by points 1, 2 and 3 is (%f, %f)\n", xc, yc);

    // Let's calculate the perimeter of the triangle formed by the three points
    double p123 = d12 + distance(x2, y2, x3, y3) + distance(x3, y3, x1, y1);
    printf("The perimeter of the triangle formed by points 1, 2 and 3 is %f\n", p123);

    return 0;
}
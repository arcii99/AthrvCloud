//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program computes the area of a triangle given its three vertices */


double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double getTriangleArea(double sideA, double sideB, double sideC) {
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

int main() {

    double x1, y1, x2, y2, x3, y3, a, b, c, area;

    printf("Enter x and y coordinates of vertex 1: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter x and y coordinates of vertex 2: ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter x and y coordinates of vertex 3: ");
    scanf("%lf %lf", &x3, &y3);

    a = getDistance(x1, y1, x2, y2);
    b = getDistance(x2, y2, x3, y3);
    c = getDistance(x3, y3, x1, y1);

    area = getTriangleArea(a,b,c);

    printf("The area of the triangle with vertices (%.1lf,%.1lf), (%.1lf,%.1lf), and (%.1lf,%.1lf) is %.2lf units^2\n", x1, y1, x2, y2, x3, y3,area);

    return 0;
}
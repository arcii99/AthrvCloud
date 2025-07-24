//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

/* Function to calculate the distance between two points */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/* Function to calculate the area of a triangle */
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double s = (a + b + c) / 2; // Calculate the semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Using Heron's formula to find the area
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the x and y coordinates of the first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the x and y coordinates of the second point: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the x and y coordinates of the third point: ");
    scanf("%lf %lf", &x3, &y3);

    // Calculate the angles of the triangle
    double a1 = atan2(y2 - y1, x2 - x1);
    double a2 = atan2(y3 - y2, x3 - x2);
    double a3 = atan2(y1 - y3, x1 - x3);

    // Convert angles to degrees
    a1 = a1 * 180 / PI;
    a2 = a2 * 180 / PI;
    a3 = a3 * 180 / PI;

    // Calculate the area of the triangle
    double tri_area = area(x1, y1, x2, y2, x3, y3);

    // Print the results
    printf("The angles of the triangle are %.2f, %.2f, and %.2f degrees.\n", a1, a2, a3);
    printf("The area of the triangle is %.2f square units.\n", tri_area);

    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>

// function to calculate the area of a triangle using Heron's formula
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// function to calculate the length of a line segment between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
    printf("Welcome to the Geometry Program!\n");

    // get user input for triangle side lengths
    double a, b, c;
    printf("Please enter the length of side a of the triangle: ");
    scanf("%lf", &a);
    printf("Please enter the length of side b of the triangle: ");
    scanf("%lf", &b);
    printf("Please enter the length of side c of the triangle: ");
    scanf("%lf", &c);

    // calculate and output the area of the triangle
    double triArea = triangleArea(a, b, c);
    printf("The area of the triangle is: %lf\n", triArea);

    // get user input for two points in 2D space
    double x1, y1, x2, y2;
    printf("Please enter the x-coordinate of point 1: ");
    scanf("%lf", &x1);
    printf("Please enter the y-coordinate of point 1: ");
    scanf("%lf", &y1);
    printf("Please enter the x-coordinate of point 2: ");
    scanf("%lf", &x2);
    printf("Please enter the y-coordinate of point 2: ");
    scanf("%lf", &y2);

    // calculate and output the distance between the two points
    double dist = distance(x1, y1, x2, y2);
    printf("The distance between the two points is: %lf\n", dist);

    return 0;
}
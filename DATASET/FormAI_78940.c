//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <math.h>

// function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt((dx * dx) + (dy * dy));
}

// function to calculate the area of a triangle using Heron's formula
double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2; // half of the perimeter
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's formula
}

int main() {
    // get user input for the three vertices of a triangle
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of vertex 1 (x1,y1): ");
    scanf("%lf,%lf", &x1, &y1);
    printf("Enter the coordinates of vertex 2 (x2,y2): ");
    scanf("%lf,%lf", &x2, &y2);
    printf("Enter the coordinates of vertex 3 (x3,y3): ");
    scanf("%lf,%lf", &x3, &y3);

    // calculate the length of each side of the triangle
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);

    // calculate the area of the triangle
    double area = triangle_area(a, b, c);

    // output the area of the triangle
    printf("The area of the triangle is %.2lf\n", area);

    return 0;
}
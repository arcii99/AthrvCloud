//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to calculate the area of a triangle using Heron's formula
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double x1, y1, x2, y2, x3, y3, a, b, c, A;

    // Prompt user for coordinates of three points
    printf("Enter the coordinates of three points on the plane:\n");
    printf("Point 1 (x y): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Point 2 (x y): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Point 3 (x y): ");
    scanf("%lf %lf", &x3, &y3);

    // Calculate the lengths of the sides of the triangle
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);

    // Calculate the area of the triangle
    A = triangleArea(a, b, c);

    // Output the results
    printf("\nThe coordinates of the three points are:\n");
    printf("(%lf,%lf)\n(%lf,%lf)\n(%lf,%lf)\n", x1, y1, x2, y2, x3, y3);
    printf("The lengths of the sides of the triangle are:\n");
    printf("a = %lf\nb = %lf\nc = %lf\n", a, b, c);
    printf("The area of the triangle is %lf\n", A);

    return 0;
}
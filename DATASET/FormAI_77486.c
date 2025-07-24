//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

// function to calculate the area of a triangle
double area_of_triangle(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

int main() {
    double a, b, c;
    printf("Enter the values of the sides of the triangle:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double area = area_of_triangle(a, b, c);
    printf("The area of the triangle is: %.2lf\n", area);
    return 0;
}
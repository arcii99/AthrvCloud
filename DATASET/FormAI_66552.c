//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include <stdio.h>
#include <math.h>

/* Computes the area of a triangle using Heron's formula */
double triangle_area(double a, double b, double c)
{
    double s = (a + b + c) / 2.0; /* semiperimeter */
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

/* Validates that the input is a valid triangle (all sides are positive and satisfy the triangle inequality) */
int is_valid_triangle(double a, double b, double c) 
{
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0; /* Not a valid triangle */
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 0; /* Not a valid triangle */
    }
    return 1; /* Valid triangle */
}

/* Main program */
int main()
{
    double a, b, c;
    printf("Enter the three sides of the triangle: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3 && is_valid_triangle(a, b, c)) {
        double area = triangle_area(a, b, c);
        printf("The area of the triangle is: %.2lf\n", area);
    } else {
        printf("Invalid input or not a valid triangle.\n");
    }
    return 0;
}
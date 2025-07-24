//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Program to calculate area of rectangle
 * inscribed in a circle of radius r
 */

int main() {
    double r, a, b, area;

    printf("Enter radius of circle: ");
    scanf("%lf", &r);

    a = r / sqrt(2);
    b = a;

    area = a * b;
    
    printf("Area of rectangle inscribed in circle of radius %.2lf = %.2lf\n", r, area);

    return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the area of the triangle by Heron's formula */

int main() {

    double a, b, c;
    double s, area;

    printf("Please enter the first side: ");
    scanf("%lf", &a);

    printf("Please enter the second side: ");
    scanf("%lf", &b);

    printf("Please enter the third side: ");
    scanf("%lf", &c);

    // Calculating semi-perimeter
    s = (a + b + c) / 2;

    // Calculating area of the triangle using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The area of the triangle is %lf", area);

    return 0;
}
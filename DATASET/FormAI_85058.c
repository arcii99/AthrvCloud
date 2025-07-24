//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// This program calculates the area of a triangle given the lengths
// of its sides using Heron's formula.

int main() {
    double a, b, c, s, area;

    // Prompt the user for the side lengths
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate the semi-perimeter
    s = (a + b + c) / 2;

    // Calculate the area using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Output the area
    printf("The area of the triangle is %.2lf square units.\n", area);

    return 0;
}
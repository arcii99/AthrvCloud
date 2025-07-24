//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include<stdio.h>
#include<math.h>

/**
 * This program calculates the area of a triangle using Heron's formula.
 * The length of the sides of the triangle are entered by the user.
 */

int main() {

    double a, b, c, s, area;    // Initialize variables

    printf("Enter the length of side A: ");
    scanf("%lf", &a);   // Get user input for side a

    printf("Enter the length of side B: ");
    scanf("%lf", &b);   // Get user input for side b

    printf("Enter the length of side C: ");
    scanf("%lf", &c);   // Get user input for side c

    // Calculate perimeter of the triangle
    s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Display the result to the user
    printf("The area of the triangle with sides %.2lf, %.2lf, %.2lf is %.2lf\n", a, b, c, area);

    return 0;
}
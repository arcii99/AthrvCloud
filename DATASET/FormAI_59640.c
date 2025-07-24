//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the area of a triangle using Heron's formula */

int main() {
    // Declare variables for triangle sides
    double a, b, c;

    // Prompt user to input triangle sides
    printf("Enter the length of side a: ");
    scanf("%lf", &a);

    printf("Enter the length of side b: ");
    scanf("%lf", &b);

    printf("Enter the length of side c: ");
    scanf("%lf", &c);

    // Calculate the semiperimeter of the triangle
    double s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Print the area of the triangle
    printf("The area of the triangle is: %lf\n", area);

    // Determine if the triangle is acute, obtuse, or right angled
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        printf("This is a right angled triangle.\n");
    } else if (a*a + b*b < c*c || a*a + c*c < b*b || b*b + c*c < a*a) {
        printf("This is an obtuse triangle.\n");
    } else {
        printf("This is an acute triangle.\n");
    }

    return 0;
}
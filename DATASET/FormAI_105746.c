//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

// This program calculates the area of a circle using geometric formulas

int main()
{
    float radius, area;

    // Prompt the user to enter the radius of the circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate the area of the circle
    area = M_PI * pow(radius, 2);

    // Display the result to the user
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);

    return 0;
}
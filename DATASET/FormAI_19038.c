//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>

/* This program calculates the area and perimeter of a circle */

#define PI 3.14159

int main()
{
    double radius, area, perimeter;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    printf("The area of the circle with radius %lf is %lf\n", radius, area);
    printf("The perimeter of the circle with radius %lf is %lf\n", radius, perimeter);

    return 0;
}
//FormAI DATASET v1.0 Category: Scientific ; Style: calm
#include <stdio.h>

// Calculate area and perimeter of a circle
// with given radius using mathematical constants PI

#define PI 3.14159265359

int main() {
    double radius, area, perimeter;

    printf("Enter radius of circle: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    printf("The area of circle with radius %lf is %lf.\n", radius, area);
    printf("The perimeter of circle with radius %lf is %lf.\n", radius, perimeter);

    return 0;
}
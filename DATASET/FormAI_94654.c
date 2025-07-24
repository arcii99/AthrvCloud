//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>

#define PI 3.14159

int main()
{
    double radius, area, perimeter;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    printf("Area of the circle with radius %lf is %lf.\n", radius, area);
    printf("Perimeter of the circle with radius %lf is %lf.\n", radius, perimeter);

    return 0;
}
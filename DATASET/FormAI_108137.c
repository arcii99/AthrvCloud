//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Program to calculate the area and perimeter of a circle */

int main()
{
    float radius, area, perimeter;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    if (radius <= 0)
    {
        printf("Invalid input. Radius must be greater than 0.\n");
        return 0;
    }

    area = M_PI * pow(radius, 2);
    perimeter = 2 * M_PI * radius;

    printf("The area of the circle is: %.2f\n", area);
    printf("The perimeter of the circle is: %.2f\n", perimeter);

    return 0;
}
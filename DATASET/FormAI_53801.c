//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the area and perimeter of a rectangle using diagonal and ratio of sides */

int main()
{
    double diagonal, ratio, a, b, area, perimeter;

    /* User input of diagonal and ratio of sides */
    printf("Enter the diagonal of the rectangle: ");
    scanf("%lf", &diagonal);
    printf("Enter the ratio of sides (a/b): ");
    scanf("%lf", &ratio);

    /* Calculation of sides using diagonal and ratio */
    a = diagonal * sqrt(ratio*ratio / (1 + ratio*ratio));
    b = diagonal * sqrt(1 / (1 + ratio*ratio));

    /* Calculation of area and perimeter */
    area = a * b;
    perimeter = 2 * (a + b);

    /* Output of area and perimeter */
    printf("The area of the rectangle is: %lf\n", area);
    printf("The perimeter of the rectangle is: %lf\n", perimeter);

    return 0;
}
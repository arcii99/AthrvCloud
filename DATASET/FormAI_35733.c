//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#include <math.h>

/* This program calculates the area and perimeter of a right triangle
 * given the length of its two legs.
 */

int main() {

    double leg1, leg2, hypotenuse, perimeter, area;

    printf("Please enter the length of the first leg of the right triangle: ");
    scanf("%lf", &leg1);

    printf("Please enter the length of the second leg of the right triangle: ");
    scanf("%lf", &leg2);

    // Calculate the hypotenuse using the Pythagorean theorem
    hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2);

    perimeter = leg1 + leg2 + hypotenuse;
    area = 0.5 * leg1 * leg2;

    printf("\nThe perimeter of the right triangle is: %.2lf", perimeter);
    printf("\nThe area of the right triangle is: %.2lf\n", area);

    return 0;
}
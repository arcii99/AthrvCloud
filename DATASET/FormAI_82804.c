//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program calculates the area of a circle with radius 'r' */

int main() {

    double r;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &r);

    double area = M_PI * pow(r, 2);
    printf("The area of the circle is: %lf\n", area);

    return 0;
}
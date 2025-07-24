//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

/* This program calculates the distance between two points in a plane. */

int main() {

    float x1, x2, y1, y2, distance;

    printf("Enter the first point (x1, y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the second point (x2, y2): ");
    scanf("%f %f", &x2, &y2);

    /*
     * The formula for the distance between two points is:
     * distance = sqrt((x2-x1)^2 + (y2-y1)^2)
     */

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("The distance between (%0.2f, %0.2f) and (%0.2f, %0.2f) is: %0.2f\n", x1, y1, x2, y2, distance);

    return 0;
}
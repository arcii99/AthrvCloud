//FormAI DATASET v1.0 Category: Scientific ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program will calculate the distance between two points in a cartesian plane */

int main()
{
    double x1, y1, x2, y2, distance;

    printf("Let's calculate the distance between two points in a cartesian plane!\n");
    printf("Enter the X-coordinate of the first point: ");
    scanf("%lf", &x1);
    printf("Enter the Y-coordinate of the first point: ");
    scanf("%lf", &y1);
    printf("Enter the X-coordinate of the second point: ");
    scanf("%lf", &x2);
    printf("Enter the Y-coordinate of the second point: ");
    scanf("%lf", &y2);

    distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    printf("\nThe distance between (%0.2lf,%0.2lf) and (%0.2lf,%0.2lf) is: %0.2lf\n", x1, y1, x2, y2, distance);

    printf("\nWOW! We just calculated the distance between two points in a cartesian plane using C!\n");

    return 0;
}
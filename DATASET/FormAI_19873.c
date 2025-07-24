//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

/* This program finds the intersection point 
   of two circles, given their centers and 
   radii. */

int main()
{
    int x1, y1, r1;
    int x2, y2, r2;
    float d, a, h, x, y;

    printf("Enter x-coordinate of center of circle 1: ");
    scanf("%d", &x1);
    printf("Enter y-coordinate of center of circle 1: ");
    scanf("%d", &y1);
    printf("Enter radius of circle 1: ");
    scanf("%d", &r1);

    printf("Enter x-coordinate of center of circle 2: ");
    scanf("%d", &x2);
    printf("Enter y-coordinate of center of circle 2: ");
    scanf("%d", &y2);
    printf("Enter radius of circle 2: ");
    scanf("%d", &r2);

    /* Calculate distance between centers */
    d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    /* If circles don't intersect at all */
    if (d > r1+r2) {
        printf("Circles are non-intersecting\n");
        return 0;
    }
    /* If one circle is contained inside the other */
    else if (d < abs(r1-r2)) {
        printf("One circle is contained inside the other\n");
        return 0;
    }
    /* If circles intersect */
    else {
        a = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2*d);
        h = sqrt(pow(r1, 2) - pow(a,2));
        x = x1 + a*(x2-x1)/d;
        y = y1 + a*(y2-y1)/d;

        /* Intersection points */
        float x3 = x + h*(y2-y1)/d;
        float y3 = y - h*(x2-x1)/d;
        float x4 = x - h*(y2-y1)/d;
        float y4 = y + h*(x2-x1)/d;

        printf("Intersection points:\n");
        printf("Point 1 (%.2f, %.2f)\n", x3, y3);
        printf("Point 2 (%.2f, %.2f)\n", x4, y4);
    }

    return 0;
}
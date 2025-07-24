//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float slope1, slope2;
    float intersection_x, intersection_y;

    printf("Enter the endpoints of both lines: x1, y1, x2, y2, x3, y3, x4, y4: ");
    scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    slope1 = (y2 - y1) / (x2 - x1);
    slope2 = (y4 - y3) / (x4 - x3);

    if (slope1 != slope2)
    {
        intersection_x = (y3 - y1 + slope1 * x1 - slope2 * x3) / (slope1 - slope2);
        intersection_y = y1 + slope1 * (intersection_x - x1);

        printf("The lines intersect at point (%f, %f)\n", intersection_x, intersection_y);
    }
    else
    {
        printf("The lines are parallel and do not intersect\n");
    }

    return 0;
}
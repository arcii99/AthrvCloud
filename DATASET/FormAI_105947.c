//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include<stdio.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float slope1, slope2, intercept1, intercept2;
    float x_intersect, y_intersect;

    printf("Enter the coordinates of the first line: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    printf("Enter the coordinates of the second line: ");
    scanf("%f%f%f%f", &x3, &y3, &x4, &y4);

    slope1 = (y2 - y1) / (x2 - x1);
    slope2 = (y4 - y3) / (x4 - x3);
    intercept1 = y1 - (slope1 * x1);
    intercept2 = y3 - (slope2 * x3);

    if (slope1 == slope2)
    {
        printf("The two lines are parallel and do not intersect.\n");
    }
    else
    {
        x_intersect = (intercept2 - intercept1) / (slope1 - slope2);
        y_intersect = slope1 * x_intersect + intercept1;
        printf("The intersection point is (%.2f, %.2f)\n", x_intersect, y_intersect);
    }

    return 0;
}
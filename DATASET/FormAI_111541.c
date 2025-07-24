//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
/* This program calculates the area of a triangle using the Shoelace Formula */

#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    double x[100], y[100], sum1 = 0, sum2 = 0;

    printf("Enter the number of vertices of the triangle: ");
    scanf("%d", &n);

    printf("Enter the coordinates of each vertex:\n");
    for (i = 0; i < n; i++)
    {
        printf("Vertex %d: ", i+1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Calculate the first sum using the Shoelace Formula
    for (i = 0; i < n-1; i++)
    {
        sum1 += x[i]*y[i+1];
    }
    sum1 += x[n-1]*y[0];

    // Calculate the second sum using the Shoelace Formula
    for (i = 0; i < n-1; i++)
    {
        sum2 += y[i]*x[i+1];
    }
    sum2 += y[n-1]*x[0];

    double area = fabs(sum1 - sum2) / 2; // Calculate the area using the absolute value function

    printf("The area of the triangle is: %lf\n", area);

    return 0;
}
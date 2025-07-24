//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_POINTS 1000000

int main()
{
    int i, count = 0;
    double x, y, pi, area;

    srand(time(NULL)); // Seed the random number generator

    // Generate NUM_POINTS random points within a square of side 2 centered at the origin
    for (i = 0; i < NUM_POINTS; i++)
    {
        x = (double) rand() / RAND_MAX * 2 - 1;
        y = (double) rand() / RAND_MAX * 2 - 1;

        // If the point is within the circle of radius 1 centered at the origin, increment the count
        if (sqrt(x * x + y * y) < 1)
        {
            count++;
        }
    }

    // Calculate the area of the circle and the value of pi
    area = 4.0 * count / NUM_POINTS;
    pi = area / 1;

    printf("Approximate value of pi = %lf\n", pi);
    printf("Area of circle = %lf\n", area);

    return 0;
}
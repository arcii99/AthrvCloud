//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
/* This program calculates the area of a circle using the Monte Carlo method */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RADIUS 5.0 // Radius of the circle
#define MAX_SAMPLES 1000000 // Maximum number of samples to take

int main()
{
    double x, y; // Coordinates of the point
    int i, inside = 0; // Counter for number of points inside the circle

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate random points and determine if they fall inside the circle
    for (i = 0; i < MAX_SAMPLES; i++)
    {
        x = (double)rand() / RAND_MAX * 2 * RADIUS - RADIUS;
        y = (double)rand() / RAND_MAX * 2 * RADIUS - RADIUS;

        if (x*x + y*y <= RADIUS*RADIUS)
        {
            inside++;
        }
    }

    // Calculate the area of the circle
    double area = (double)inside / MAX_SAMPLES * (2 * RADIUS) * (2 * RADIUS);

    // Display the result
    printf("The area of the circle is %.2f\n", area);

    return 0;
}
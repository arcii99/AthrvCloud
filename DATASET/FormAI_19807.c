//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Enter your chosen mathematical function here
double myFunction(double x) {
    return sin(x) + cos(x);
}

// The main function which calculates the definite integral of the given function
double definiteIntegral(double lowerLimit, double upperLimit, int numIntervals) {
    // Declare variables
    double deltaX, x, area;
    int i;

    // Calculate the width of each interval
    deltaX = (upperLimit - lowerLimit) / numIntervals;

    // Initialize area
    area = 0.0;

    // Loop through each interval and calculate the area
    for (i = 0; i < numIntervals; i++) {
        // Calculate the x-coordinate at the left endpoint of the interval
        x = lowerLimit + i * deltaX;
        // Add the area of the current rectangle to the total area
        area += myFunction(x) * deltaX;
    }

    // Return the total area
    return area;
}

int main() {
    // Declare variables
    double lowerLimit, upperLimit, area;
    int numIntervals;

    // Seed the random number generator so we get a different result each time we run the program
    srand(time(NULL));

    // Generate random limits and number of intervals
    lowerLimit = (double) rand() / RAND_MAX * 10;
    upperLimit = (double) rand() / RAND_MAX * 10;
    numIntervals = rand() % 100 + 1;

    // Calculate the definite integral
    area = definiteIntegral(lowerLimit, upperLimit, numIntervals);

    // Print out the results
    printf("The definite integral of sin(x) + cos(x) from %lf to %lf using %d intervals is:\n", lowerLimit, upperLimit, numIntervals);
    printf("%lf\n", area);

    // Return 0 to indicate successful completion of the program
    return 0;
}
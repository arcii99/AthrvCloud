//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of iterations for the program
#define ITERATIONS 10000000

int main() {

    // Declare variables to hold the sum and square root of the sum
    double sum = 0.0;
    double squareRootSum = 0.0;

    // Execute the loop for the number of iterations specified
    for (int i = 1; i <= ITERATIONS; i++) {

        // Increment the sum by the inverse of the square root of the current iteration
        sum += 1.0 / sqrt((double)i);

        // Calculate the square root of the sum
        squareRootSum = sqrt(sum);
    }

    // Output the result
    printf("The square root of the sum is %f\n", squareRootSum);

    return 0;
}
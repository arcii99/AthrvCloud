//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    srand(time(NULL));

    // Declare variables
    int i, n = 10;
    double x[n], mean, variance, std_dev, sum = 0, sum_squares = 0;

    // Generate n random numbers between 0 and 1
    for (i = 0; i < n; i++) {
        x[i] = rand() / (double) RAND_MAX;
        sum += x[i];
        sum_squares += pow(x[i], 2);
    }

    // Calculate the mean
    mean = sum / n;

    // Calculate the variance
    variance = (sum_squares / n) - pow(mean, 2);

    // Calculate the standard deviation
    std_dev = sqrt(variance);

    // Display the results
    printf("The random numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%.4f ", x[i]);
    }
    printf("\n\nThe mean is: %.4f\n", mean);
    printf("The variance is: %.4f\n", variance);
    printf("The standard deviation is: %.4f\n\n", std_dev);

    return 0;
}
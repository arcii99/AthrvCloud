//FormAI DATASET v1.0 Category: Data mining ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the main function
int main() {

    // Define the data set to be mined
    double dataset[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    // Calculate the mean of the dataset
    double sum = 0;
    int i, n = 10;
    for (i = 0; i < n; i++) {
        sum += dataset[i];
    }
    double mean = sum / n;

    // Calculate the standard deviation of the dataset
    double variance = 0;
    for (i = 0; i < n; i++) {
        variance += pow(dataset[i] - mean, 2);
    }
    double std_dev = sqrt(variance / n);

    // Print the mean and standard deviation of the dataset
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", std_dev);

    // Detect any outliers in the dataset
    double threshold = 2;
    for (i = 0; i < n; i++) {
        if (fabs(dataset[i] - mean) > threshold * std_dev) {
            printf("Outlier detected at index %d: %.2f\n", i, dataset[i]);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n = 10; // Number of data points

    // Generate some example data
    float data[n];
    for (int i = 0; i < n; i++) {
        data[i] = sin(i * M_PI / 6) + 0.5 * cos(i * M_PI / 3) + 0.1 * rand() / RAND_MAX;
    }

    // Calculate the mean
    float mean = 0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;

    // Calculate the standard deviation
    float stdev = 0;
    for (int i = 0; i < n; i++) {
        stdev += pow(data[i] - mean, 2);
    }
    stdev = sqrt(stdev / n);

    // Calculate the skewness
    float skewness = 0;
    for (int i = 0; i < n; i++) {
        skewness += pow(data[i] - mean, 3);
    }
    skewness = (sqrt(n) * skewness) / ((n - 1) * pow(stdev, 3));

    // Calculate the kurtosis
    float kurtosis = 0;
    for (int i = 0; i < n; i++) {
        kurtosis += pow(data[i] - mean, 4);
    }
    kurtosis = ((n * (n + 1) / ((n - 1) * (n - 2) * (n - 3))) * kurtosis / pow(stdev, 4)) - (3 * pow(n - 1, 2) / ((n - 2) * (n - 3)));

    // Print the results
    printf("Data points:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %f\n", i+1, data[i]);
    }
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", stdev);
    printf("Skewness: %f\n", skewness);
    printf("Kurtosis: %f\n", kurtosis);

    return 0;
}
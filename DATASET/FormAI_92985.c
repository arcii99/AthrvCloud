//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>

int main() {
    // Define an array of data
    int data[10] = {4, 7, 2, 9, 3, 1, 6, 8, 5, 10};

    // Calculate the mean
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    double mean = sum / 10;

    // Calculate the variance
    double variance_sum = 0;
    for (int i = 0; i < 10; i++) {
        variance_sum += (data[i] - mean) * (data[i] - mean);
    }
    double variance = variance_sum / 10;

    // Determine the outliers
    double threshold = mean + (2 * variance);
    printf("The outlier threshold is %f.\n", threshold);
    for (int i = 0; i < 10; i++) {
        if (data[i] > threshold) {
            printf("%d is an outlier.\n", data[i]);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the number of data points
#define DATA_POINTS 10

int main() {

    // Array to store the data points
    int data[DATA_POINTS] = {85, 76, 92, 81, 69, 75, 88, 93, 78, 86};

    // Calculate the average of the data points
    int sum = 0;
    for (int i = 0; i < DATA_POINTS; i++) {
        sum += data[i];
    }
    double average = (double)sum / DATA_POINTS;

    // Calculate the variance of the data points
    double variance = 0;
    for (int i = 0; i < DATA_POINTS; i++) {
        variance += (data[i] - average) * (data[i] - average);
    }
    variance /= DATA_POINTS;

    // Calculate the standard deviation of the data points
    double std_dev = sqrt(variance);

    // Print out the statistical values
    printf("Data Points: ");
    for (int i = 0; i < DATA_POINTS; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Average: %0.2f\n", average);
    printf("Variance: %0.2f\n", variance);
    printf("Standard Deviation: %0.2f\n", std_dev);

    return 0;
}
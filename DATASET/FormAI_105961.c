//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
double getAverage(int *arr, int size);
double getStandardDeviation(int *arr, int size, double mean);

int main() {
    // Initialize the random number generator
    srand((unsigned) time(NULL));

    // Generate an array of 100 random integers between 1 and 100
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Calculate the average and standard deviation of the array
    double mean = getAverage(arr, 100);
    double stdev = getStandardDeviation(arr, 100, mean);

    // Print the results
    printf("Average: %f\n", mean);
    printf("Standard deviation: %f\n", stdev);

    return 0;
}

double getAverage(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

double getStandardDeviation(int *arr, int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / (size - 1));
}
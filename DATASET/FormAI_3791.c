//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 100000

/* Function to calculate the average of an array of doubles */
double average(double arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total / size;
}

/* Function to calculate the standard deviation of an array of doubles */
double standardDeviation(double arr[], int size) {
    double avg = average(arr, size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    return sqrt(sum / size);
}

int main() {
    double arr[NUM_ELEMENTS];
    srand(time(NULL));
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = (double) rand() / RAND_MAX;
    }

    clock_t start = clock();

    double avg = average(arr, NUM_ELEMENTS);
    printf("Average: %f\n", avg);
    double stdDev = standardDeviation(arr, NUM_ELEMENTS);
    printf("Standard Deviation: %f\n", stdDev);

    clock_t end = clock();
    double time_spent = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}
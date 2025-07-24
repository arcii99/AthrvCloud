//FormAI DATASET v1.0 Category: Scientific ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    srand(time(NULL));

    int arr[SIZE];
    float mean, variance, deviation;

    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101;
    }

    // Calculate mean
    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    mean = (float) sum / SIZE;
    printf("The mean of the data is %.2f\n", mean);

    // Calculate variance
    float sumOfSquaredDifferences = 0;
    for(int i = 0; i < SIZE; i++) {
        sumOfSquaredDifferences += (arr[i] - mean) * (arr[i] - mean);
    }
    variance = sumOfSquaredDifferences / SIZE;
    printf("The variance of the data is %.2f\n", variance);

    // Calculate deviation
    deviation = sqrt(variance);
    printf("The standard deviation of the data is %.2f\n", deviation);

    return 0;
}
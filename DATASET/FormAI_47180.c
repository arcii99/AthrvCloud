//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    // Initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate average of array
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    float avg = (float) sum / ARRAY_SIZE;

    // Calculate standard deviation of array
    float variance = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        variance += (arr[i] - avg) * (arr[i] - avg);
    }
    float std_deviation = sqrt(variance / ARRAY_SIZE);

    printf("Average: %f\n", avg);
    printf("Standard Deviation: %f\n", std_deviation);

    return 0;
}
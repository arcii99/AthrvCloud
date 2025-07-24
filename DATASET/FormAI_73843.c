//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Configurable parameters
#define NUM_ITERATIONS 5
#define RAM_USAGE 1024 // In MB

// Function to generate random integers between 1 and 100
int* generate_random_numbers(int size) {
    int* arr = malloc(sizeof(int) * size);
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    return arr;
}

// Function to calculate the sum of an array
int calculate_sum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Allocate RAM according to configuration
    int** arr = malloc(sizeof(int*) * RAM_USAGE);
    for (int i = 0; i < RAM_USAGE; i++) {
        arr[i] = malloc(sizeof(int) * ARRAY_SIZE);
    }
    printf("%d MB of RAM allocated\n", RAM_USAGE);

    // Generate random numbers and calculate sum for configured number of iterations
    int sum = 0;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        int* random_numbers = generate_random_numbers(ARRAY_SIZE);
        sum += calculate_sum(random_numbers, ARRAY_SIZE);
        free(random_numbers);
    }

    printf("Total sum of random numbers: %d\n", sum);

    // Deallocate RAM
    for (int i = 0; i < RAM_USAGE; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
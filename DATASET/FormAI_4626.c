//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_ITERATIONS 10000

// Function to populate the array with random numbers
void populate_array(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Function to calculate the sum of all elements in the array
int calculate_sum(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to benchmark the time taken for the array sum calculation
void benchmark(int* array, int size) {
    clock_t start_time, end_time;
    double total_time = 0;
    int sum = 0;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        start_time = clock();

        sum = calculate_sum(array, size);

        end_time = clock();

        total_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    printf("Average time taken for %d iterations: %f seconds\n", NUM_ITERATIONS, (total_time/NUM_ITERATIONS));
    printf("Result: %d\n", sum);
}

int main() {
    int array[ARRAY_SIZE];

    populate_array(array, ARRAY_SIZE);
    benchmark(array, ARRAY_SIZE);

    return 0;
}
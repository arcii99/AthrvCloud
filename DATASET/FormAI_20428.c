//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_ITERATIONS 10000

// Configurable parameters
#define RANDOM_THRESHOLD 5
#define ADD_THRESHOLD 2

// Global variables
int array[ARRAY_SIZE];
int sum = 0;

// Function to generate a random number between 0 and 9
int random_num() {
    return rand() % 10;
}

// Function to add two numbers and update the global variable sum
void add_nums(int num1, int num2) {
    sum += num1 + num2;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = random_num();
    }

    // Start measuring the time taken for the performance-critical code
    clock_t start_time = clock();

    // Run the performance-critical code NUM_ITERATIONS times
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Iterate over the array and perform operations based on the random values
        for (int j = 0; j < ARRAY_SIZE; j++) {
            int random_val = random_num();
            if (random_val < RANDOM_THRESHOLD) {
                // Set the current array element to a random value
                array[j] = random_num();
            } else if (random_val < RANDOM_THRESHOLD + ADD_THRESHOLD) {
                // Add the current and next array element
                add_nums(array[j], array[j + 1]);
            }
        }
    }

    // Calculate the time taken for the performance-critical code
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the sum and the time taken
    printf("Sum: %d\n", sum);
    printf("Time taken: %fs\n", time_taken);

    return 0;
}
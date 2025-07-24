//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 1000
#define MAX_ITERATIONS 1000

// A function to generate random numbers between 0 and MAX_NUMBER
int generate_random_number() {
    return rand() % (MAX_NUMBER + 1);
}

// A function to perform some simple computations
void perform_computations() {
    int i, j, k;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        for (j = 0; j < MAX_ITERATIONS; j++) {
            for (k = 0; k < MAX_ITERATIONS; k++) {
                int result = (i * j) + k;
            }
        }
    }
}

// The main function
int main() {
    int i;
    double total_time = 0;
    clock_t start, end;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Perform the computations MAX_ITERATIONS times and calculate the total running time
    for (i = 0; i < MAX_ITERATIONS; i++) {
        start = clock();
        
        // Generate a random number and perform some computations
        int random_number = generate_random_number();
        perform_computations();
        
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    // Calculate the average running time over MAX_ITERATIONS iterations
    double average_time = total_time / MAX_ITERATIONS;
    
    // Print the average running time
    printf("The average running time over %d iterations is: %f seconds\n", MAX_ITERATIONS, average_time);
    
    return 0;
}
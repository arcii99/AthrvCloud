//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // Define the number of elements in array

int main(){
    int array[ARRAY_SIZE]; // Initialize an array with ARRAY_SIZE

    // Fill the array with random numbers
    srand(time(NULL)); // Seed the random number generator with time
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = rand() % 100;
    }

    // Benchmarking begins
    clock_t begin = clock(); // Start the clock

    // Perform some operation on the array
    int sum = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        sum += array[i];
    }

    clock_t end = clock(); // Stop the clock
    // Benchmarking ends

    // Calculate elapsed CPU time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}
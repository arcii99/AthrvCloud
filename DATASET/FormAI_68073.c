//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // defining the size of the array

int main(int argc, char* argv[]) {

    int i, sum = 0, average;
    clock_t start_time, end_time; // variables to store CPU clock ticks
    
    int* array = malloc(ARRAY_SIZE * sizeof(int)); // dynamically allocating memory for the array
    
    // initializing the array with random numbers between 0 to 999
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }
    
    printf("Calculating the sum of %d elements...\n", ARRAY_SIZE);
    
    // measuring the CPU clock ticks before executing the loop
    start_time = clock();
    
    // calculating the sum of all elements in the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    
    // measuring the CPU clock ticks after executing the loop
    end_time = clock();
    
    // calculating the average of the array elements
    average = sum / ARRAY_SIZE;
    
    printf("Sum: %d\n", sum);
    printf("Average: %d\n", average);
    printf("Time taken: %f seconds\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);

    free(array); // deallocating the memory
    
    return 0;
}
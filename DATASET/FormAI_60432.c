//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_LOOPS 100000

int main() {
    int array[ARRAY_SIZE]; //create an array to store random numbers
    long long total_time = 0; //initialize total benchmarking time
    int i, j, temp; //counter variables and temporary variable for swapping
    
    srand(time(NULL)); //seed the random number generator with the current time
    
    //fill the array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }
    
    //start benchmarking the sort algorithm
    clock_t start_time = clock(); //get starting time
    for (i = 0; i < NUM_LOOPS; i++) { //perform multiple iterations for more accurate results
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j + 1]) { //if adjacent elements are out of order
                temp = array[j]; //swap them
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    clock_t end_time = clock(); //get ending time
    
    //calculate total benchmarking time and print results
    total_time = (end_time - start_time) * 1000 / CLOCKS_PER_SEC; //convert clock cycles to milliseconds
    printf("Total time taken for %d iterations: %lld milliseconds\n", NUM_LOOPS, total_time);
    return 0;
}
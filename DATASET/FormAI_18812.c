//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // array size for benchmarking
#define MAX_NUM 1000 // maximum value for generating random numbers

int main()
{
    // seed random number generator
    srand(time(NULL));
    
    // initialize array with random values
    int arr[ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_NUM;
    }
    
    // start benchmarking
    clock_t start = clock();
    
    // perform some operations on the array
    int sum = 0;
    for(int i=0; i<ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    double average = (double) sum / ARRAY_SIZE;
    
    // end benchmarking
    clock_t end = clock();
    
    // calculate elapsed time in milliseconds
    double elapsed_time = (double) (end - start) * 1000.0 / CLOCKS_PER_SEC;
    
    // print results
    printf("Array size: %d\n", ARRAY_SIZE);
    printf("Maximum number: %d\n", MAX_NUM);
    printf("Sum of array values: %d\n", sum);
    printf("Average of array values: %f\n", average);
    printf("Elapsed time: %f milliseconds\n", elapsed_time);
    
    return 0;
}
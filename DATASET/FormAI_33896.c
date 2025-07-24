//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE]; // initialize array of size SIZE
    
    // initialize random seed
    srand(time(NULL));
    
    // populate array with random numbers
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    // initialize variables for computing the average
    int sum = 0;
    float avg;
    
    // start the benchmarking timer
    clock_t start = clock();
    
    // compute the sum of all elements in the array
    for(int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    
    // compute the average value of the array
    avg = (float)sum / SIZE;
    
    // stop the benchmarking timer
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC; // compute the duration in seconds
    
    // output the results
    printf("Sum of array elements = %d\n", sum);
    printf("Average value of array = %.2f\n", avg);
    printf("Computing the sum and average of the array took %.2f seconds.\n", duration);
    
    return 0;
}
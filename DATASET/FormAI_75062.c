//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of elements in an array
#define N 1000000

int main()
{
    // Declare variables
    int i,j,k;
    int temp;
    int array[N];
    
    // Initialize the random number generator
    srand(time(NULL));
    
    // Fill the array with random numbers
    for(i=0;i<N;i++){
        array[i] = rand();
    }
    
    // Start the timer
    clock_t start = clock();
    
    // Sort the array using bubble sort
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(array[j]>array[j+1]){
                // Swap the elements
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    // Stop the timer
    clock_t end = clock();
    
    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    
    // Print the elapsed time
    printf("Elapsed time in seconds: %f", elapsed_time);
    
    return 0;
}
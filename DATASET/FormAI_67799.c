//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    clock_t start_time, end_time;
    double total_time;
    
    // Allocate memory for the array
    int *array = malloc(sizeof(int) * ARRAY_SIZE);
    
    // Fill the array with random integers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }
    
    // Get the starting time
    start_time = clock();
    
    // Sort the array using bubble sort algorithm
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    // Get the ending time
    end_time = clock();
    
    // Calculate the total time taken for sorting
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("Time taken to sort %d integers using bubble sort: %f seconds\n", ARRAY_SIZE, total_time);
    
    // Free the allocated memory
    free(array);
    
    return 0;
}
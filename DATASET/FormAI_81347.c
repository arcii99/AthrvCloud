//FormAI DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
/* Claude Shannon Style Benchmarking Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int *array = malloc(sizeof(int) * ARRAY_SIZE); // Allocate memory for array
    
    // Fill array with random values between 1 and 100000
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100000 + 1;
    }
    
    // Use bubble sort to sort the array and measure time taken
    clock_t start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    // Print sorted array and time taken to sort
    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nTime taken to sort: %.8f seconds\n", time_taken);
    
    free(array); // Free allocated memory
    
    return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int arr[ARRAY_SIZE];
    int i, j, temp;
    clock_t start, end;
    double time_taken;
    
    srand(time(NULL)); // Seed the random number generator
    
    // Fill the array with random numbers between 0 and 99
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    start = clock(); // Start the timer
    
    // Sort the array using bubble sort
    for (i = 0; i < ARRAY_SIZE-1; i++) {
        for (j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    end = clock(); // End the timer
    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);
    
    // Print out the first 10 numbers in the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
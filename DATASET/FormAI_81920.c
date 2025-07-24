//FormAI DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {

    int array[MAX_SIZE];
    int i, j, temp;
    int size = MAX_SIZE;

    clock_t start, end;
    double cpu_time_used;

    // Randomly populate the array with integers
    for(i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Perform a bubble sort on the array
    for(i = 0; i < size; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // End the timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array and time taken for sorting
    printf("Sorted array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken for sorting: %f seconds", cpu_time_used);

    return 0;
}
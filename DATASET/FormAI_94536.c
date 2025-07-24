//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE], i, j, temp;
    struct timespec start, end;
    double elapsed_time;

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Bubble sort algorithm
    clock_gettime(CLOCK_REALTIME, &start);

    for (i = 0; i < SIZE-1; i++) {
        for (j = 0; j < SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate elapsed time in milliseconds
    elapsed_time = (end.tv_sec - start.tv_sec) * 1e3;
    elapsed_time += (end.tv_nsec - start.tv_nsec) / 1e6;
    
    // Print sorted array and elapsed time
    printf("Sorted array: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nElapsed time: %f ms", elapsed_time);

    return 0;
}
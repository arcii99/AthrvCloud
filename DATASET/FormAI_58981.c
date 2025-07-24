//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // Fill array with random numbers
    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Bubble sort
    start = clock();
    for(i = 0; i < SIZE-1; i++) {
        for(j = 0; j < SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
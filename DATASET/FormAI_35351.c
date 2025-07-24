//FormAI DATASET v1.0 Category: Benchmarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000 // Change array size as per your memory availability

int main() {
    int *arr = malloc(sizeof(int) * ARRAY_SIZE);
    if (arr == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Fill array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Benchmarking of sorting algorithm
    clock_t start_time, end_time;
    double time_taken;
    start_time = clock();
    
    // Bubble sort algorithm
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to sort array of %d integers using bubble sort: %f seconds\n", ARRAY_SIZE, time_taken);

    free(arr);
    return 0;
}
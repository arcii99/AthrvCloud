//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <time.h>

#define NUM_ELEMENTS 10000000

int main() {
    int arr[NUM_ELEMENTS];
    srand(time(0));
    
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = rand() % 1000; // Filling array with random numbers from 0-999
    }

    clock_t start = clock();

    // Bubble Sort
    for(int i = 0; i < NUM_ELEMENTS - 1; i++) {
        for(int j = 0; j < NUM_ELEMENTS - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array in %f seconds:\n", time_taken);
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 1000000

int main() {
    int i, j, temp;
    clock_t t1, t2; // variables for time measurement
    int arr[ARRAY_SIZE];
    srand(time(NULL)); // initializing random seed
    
    // filling array with random integers between 0 and 99
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    // bubble sort algorithm benchmarking
    t1 = clock(); // starting time measurement
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    t2 = clock(); // ending time measurement
    
    // printing sorted array
    printf("Bubble sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // displaying benchmarking results
    printf("Bubble sort algorithm took %f seconds to execute.\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    
    return 0;
}
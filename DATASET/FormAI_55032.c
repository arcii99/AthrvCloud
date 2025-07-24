//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    int *arr = (int *) malloc(sizeof(int) * ARRAY_SIZE); // allocating memory for array
    
    srand(time(NULL)); // initializing random number generator
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000; // filling array with random numbers
    }
    
    // Bubble sort algorithm for sorting array in ascending order
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]); // printing sorted array
    }
    
    free(arr); // freeing allocated memory
    
    return 0;
}
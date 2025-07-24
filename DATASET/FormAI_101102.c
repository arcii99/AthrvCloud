//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 10000000

int main() {
    int *arr = (int*) calloc(NUM_ELEMENTS, sizeof(int));

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort the array using insertion sort algorithm
    for (int i = 1; i < NUM_ELEMENTS; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print the sorted array
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

int main() {
    int arr[ARR_SIZE];

    // Filling the array with random values
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand();
    }

    // Sorting the array using bubble sort algorithm
    clock_t start = clock();
    for (int i = 0; i < ARR_SIZE - 1; i++) {
        for (int j = 0; j < ARR_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Printing the sorted array
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSorting time: %f seconds", time_spent);

    return 0;
}
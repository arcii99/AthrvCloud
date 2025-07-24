//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    int arr[SIZE];
    int i, j, temp, min_index;

    // Initialize array with random numbers
    srand((unsigned) time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    // Selection Sort Algorithm
    for (i = 0; i < SIZE - 1; i++) {
        min_index = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }

    // Print sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

void bubble_sort(int *arr, int n) {
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        int swapped = 0;
        for (j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int i, *arr;
    arr = (int*)malloc(N * sizeof(int));

    // Fill array with random numbers
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    
    // Sort array using bubble sort
    bubble_sort(arr, N);

    // Print sorted array
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
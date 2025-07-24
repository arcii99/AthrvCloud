//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10000], n = 10000;
    clock_t start, end;
    double time_taken;

    // Initializing array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    start = clock();

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken for sorting the array with bubble sort algorithm: %lf seconds", time_taken);

    return 0;
}
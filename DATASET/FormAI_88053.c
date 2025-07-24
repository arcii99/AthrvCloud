//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000 // Maximum number of elements in array

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX];

    // Generate random array of numbers
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 1000000;
    }

    // Benchmark Bubble Sort algorithm
    clock_t start = clock();
    bubbleSort(arr, MAX);
    clock_t end = clock();
    double time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print sorted array and time taken for sorting
    printf("Sorted array: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_spent);

    return 0;
}
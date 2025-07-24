//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10000

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = arr[end];
        int i = (start - 1);
        for (int j = start; j <= end - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        int partitionIndex = (i + 1);
        quicksort(arr, start, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, end);
    }
}

int main() {
    int arr[ARR_SIZE];

    // Randomize array
    srand((unsigned int) time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Measure time taken to sort array
    clock_t start = clock();
    quicksort(arr, 0, ARR_SIZE - 1);
    clock_t end = clock();

    // Print sorted array
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);   
    }

    // Print time taken
    printf("\n\nTime taken: %lf sec\n", (double) (end - start) / CLOCKS_PER_SEC);
    
    return 0;
}
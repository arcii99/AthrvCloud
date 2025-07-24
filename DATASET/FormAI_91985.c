//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Benchmarking Program!\n\n");

    int size = 1000000;
    int *arr = (int*) malloc(size * sizeof(int));

    printf("Randomly Generating %d Numbers...\n", size);
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    clock_t start, end;
    double time_taken;

    // Sorting Algorithm 1: Bubble Sort
    printf("\nSorting Using Bubble Sort...\n");
    start = clock();
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Bubble Sort Time Taken: %f seconds\n", time_taken);

    // Sorting Algorithm 2: Quick Sort
    printf("\nSorting Using Quick Sort...\n");
    start = clock();
    quickSort(arr, 0, size-1);
    end = clock();
    time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Quick Sort Time Taken: %f seconds\n", time_taken);

    free(arr);
    printf("\nGoodbye! Exiting Program...\n");

    return 0;
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i+1);
}
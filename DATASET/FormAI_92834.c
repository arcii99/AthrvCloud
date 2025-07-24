//FormAI DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(NULL)); // seed random number generator

    // generate random array
    for (int i = 0; i < SIZE; i++) 
        arr[i] = rand();

    printf("Unsorted Array:\n");
    printArray(arr, SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arr, 0, SIZE - 1);
    end = clock();

    printf("Sorted Array:\n");
    printArray(arr, SIZE);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
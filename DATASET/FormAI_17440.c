//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[N];
    clock_t t;

    // generate random numbers between 0 and 999
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
    }

    // sort the array using quicksort and measure the time
    t = clock();
    quickSort(arr, 0, N-1);
    t = clock() - t;

    // print the sorted array and the execution time
    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nExecution time: %.2f seconds", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}
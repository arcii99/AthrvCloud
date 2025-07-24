//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    printf("Get ready to benchmark the quicksort algorithm!\n");

    // generate random array of 10,000 numbers
    int arr[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }

    // benchmark quicksort
    clock_t start = clock();
    quickSort(arr, 0, 9999);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Quicksort benchmark results:\n");
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}
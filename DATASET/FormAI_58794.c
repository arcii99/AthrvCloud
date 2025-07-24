//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {

    int n = 10000;
    int arr[n], i;

    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand();

    clock_t start, end;

    start = clock();
    bubble_sort(arr, n);
    end = clock();

    printf("Time taken by bubble sort: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand();

    start = clock();
    selection_sort(arr, n);
    end = clock();

    printf("Time taken by selection sort: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}
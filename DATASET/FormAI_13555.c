//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10000

void selection_sort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;

        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right) {
    int i, j, pivot, temp;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < right)
                i++;

            while (arr[j] > arr[pivot])
                j--;

            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quick_sort(arr, left, j-1);
        quick_sort(arr, j+1, right);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i;

    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000000;
    }

    clock_t start, end;

    start = clock();
    selection_sort(arr, ARRAY_SIZE);
    end = clock();

    double selection_sort_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by selection sort: %f seconds\n", selection_sort_time);

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000000;
    }

    start = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end = clock();

    double bubble_sort_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by bubble sort: %f seconds\n", bubble_sort_time);

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000000;
    }

    start = clock();
    quick_sort(arr, 0, ARRAY_SIZE-1);
    end = clock();

    double quick_sort_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by quick sort: %f seconds\n", quick_sort_time);

    return 0;
}
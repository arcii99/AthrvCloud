//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    int pivot, i, j, temp;
    if (low < high) {
        pivot = low;
        i = low;
        j = high;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i <= high)
                i++;
            while (arr[j] > arr[pivot] && j >= low)
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE], i;
    clock_t start, end;
    double bubbleSortTime, quickSortTime;
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
    }
    start = clock();
    bubbleSort(arr1, ARRAY_SIZE);
    end = clock();
    bubbleSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f seconds\n", bubbleSortTime);
    start = clock();
    quickSort(arr2, 0, ARRAY_SIZE - 1);
    end = clock();
    quickSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort time: %f seconds\n", quickSortTime);
    return 0;
}
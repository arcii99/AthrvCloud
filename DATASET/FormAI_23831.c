//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000 // size of the array

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int i = low, j = high, pivot = arr[low], temp;
        while (i < j) {
            while (i < j && arr[j] >= pivot)
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            while (i < j && arr[i] <= pivot)
                ++i;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = pivot;
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

double getExecutionTime(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int i, arr[ARRAY_SIZE], arrCopy[ARRAY_SIZE];
    clock_t start, end;
    double timeTaken;

    // generate a random array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand();

    // copy array for sort testing
    for (i = 0; i < ARRAY_SIZE; i++)
        arrCopy[i] = arr[i];

    // measure bubble sort time
    start = clock();
    bubbleSort(arrCopy, ARRAY_SIZE);
    end = clock();
    timeTaken = getExecutionTime(start, end);
    printf("Bubble Sort Time: %f seconds.\n", timeTaken);

    // copy array for sort testing
    for (i = 0; i < ARRAY_SIZE; i++)
        arrCopy[i] = arr[i];

    // measure quick sort time
    start = clock();
    quickSort(arrCopy, 0, ARRAY_SIZE - 1);
    end = clock();
    timeTaken = getExecutionTime(start, end);
    printf("Quick Sort Time: %f seconds.\n", timeTaken);

    return 0;
}
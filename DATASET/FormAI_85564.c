//FormAI DATASET v1.0 Category: Benchmarking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

double bubbleSort(int arr[]) {
    clock_t start, end;
    double time;
    start = clock();

    int n = SIZE;
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

double quickSort(int arr[], int low, int high) {
    clock_t start, end;
    double time;
    start = clock();

    int pivot, j, i;
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
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;

        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }

    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time;
}

int main() {
    int arr[SIZE], arr1[SIZE]; 
    int i;

    // Generate random numbers to populate arrays
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;
        arr1[i] = arr[i];
    }

    double bubbleTime, quickTime;

    // Benchmark bubble sort
    bubbleTime = bubbleSort(arr);
    printf("Bubble Sort Time: %lf sec\n", bubbleTime);

    // Benchmark quick sort
    quickTime = quickSort(arr1, 0, SIZE-1);
    printf("Quick Sort Time: %lf sec\n", quickTime);

    return 0;
}
//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 1000000

int main()
{
    int arr[MAX_ELEMENTS];
    clock_t start, end;
    double cpu_time_used;

    // Fill the array with random integers
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        arr[i] = rand() % MAX_ELEMENTS;
    }

    // Measure the time taken to sort the array using bubble sort
    start = clock();

    for(int i = 0; i < MAX_ELEMENTS - 1; i++) {
        for(int j = 0; j < MAX_ELEMENTS - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %f seconds\n", cpu_time_used);

    // Measure the time taken to sort the array using quick sort
    start = clock();

    quickSort(arr, 0, MAX_ELEMENTS-1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for quick sort: %f seconds\n", cpu_time_used);

    return 0;
}

// Recursive implementation of quick sort algorithm
void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
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
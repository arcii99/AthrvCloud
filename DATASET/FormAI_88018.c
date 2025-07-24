//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    srand(time(NULL)); // seed for random number generation

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // fill array with random integers
    }

    // Create two variables to keep track of the total time taken by each sorting algorithm
    double bubbleSortTime, quickSortTime;

    clock_t start = clock(); // start the timer
    for (int i = 0; i < SIZE - 1; i++) { // Bubble Sort algorithm
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end = clock(); // stop the timer

    bubbleSortTime = (double) (end - start) / CLOCKS_PER_SEC; // calculate Bubble Sort time in seconds

    start = clock(); // start the timer again
    quickSort(arr, 0, SIZE - 1); // Quick Sort algorithm
    end = clock(); // stop the timer again

    quickSortTime = (double) (end - start) / CLOCKS_PER_SEC; // calculate Quick Sort time in seconds

    printf("Bubble Sort took %f seconds for sorting an array of %d elements.\n", bubbleSortTime, SIZE);
    printf("Quick Sort took %f seconds for sorting an array of %d elements.\n", quickSortTime, SIZE);

    return 0;
}

// Quick Sort implementation
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int partitionIndex = partition(arr, left, right); // find partition index

        quickSort(arr, left, partitionIndex - 1); // sort left partition
        quickSort(arr, partitionIndex + 1, right); // sort right partition
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // choose rightmost element as pivot
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}
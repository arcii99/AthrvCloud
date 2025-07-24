//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // constant to define array size

// Function to generate random integer numbers
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to implement bubble sort
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to implement quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find partition for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int main() {
    int n = ARRAY_SIZE;
    int arr[n];
    int i;
    clock_t start_time, end_time;
    double bubbleSort_time, quickSort_time;

    srand(time(NULL)); // seed for random number generator

    // Generate random numbers and store in array
    for (i = 0; i < n; i++) {
        arr[i] = generateRandomNumber(0, 1000000);
    }

    // Measure execution time for bubble sort
    start_time = clock();
    bubbleSort(arr, n);
    end_time = clock();
    bubbleSort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken by Bubble Sort: %f seconds\n", bubbleSort_time);

    // Measure execution time for quick sort
    start_time = clock();
    quickSort(arr, 0, n - 1);
    end_time = clock();
    quickSort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken by Quick Sort: %f seconds\n", quickSort_time);

    return 0;
}
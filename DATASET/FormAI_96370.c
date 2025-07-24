//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int array[ARRAY_SIZE];

// Function to fill an array with random values between 1 and 1000
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// Bubble Sort algorithm to sort an array in ascending order
void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Fill the array with random values
    fillArray(array, ARRAY_SIZE);

    // Calculate the time taken to fill the array
    clock_t start = clock();
    fillArray(array, ARRAY_SIZE);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to fill the array: %f seconds\n", time_taken);

    // Calculate the time taken to sort the array using Bubble Sort algorithm
    start = clock();
    bubbleSort(array, ARRAY_SIZE);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort the array: %f seconds\n", time_taken);

    return 0;
}
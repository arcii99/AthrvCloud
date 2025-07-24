//FormAI DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines the size of the array to be benchmarked
#define ARRAY_SIZE 1000000

// Function to perform bubble sort on an array of integers
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Initializing seed for random number generation
    srand(time(NULL));

    // Creating an array of random integers
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100000;
    }

    // Benchmarking bubble sort on the array
    clock_t start = clock();
    bubbleSort(array, ARRAY_SIZE);
    clock_t end = clock();

    // Printing the sorted array and time taken to sort it
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken: %lf seconds", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
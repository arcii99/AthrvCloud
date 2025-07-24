//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Function to generate random integer array
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

// Function to print integer array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort integer array using bubble sort
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
    int arr[MAX_SIZE];
    generateRandomArray(arr, MAX_SIZE);
    printf("Unsorted array: \n");
    // Uncomment below line to enable printing unsorted array
    //printArray(arr, MAX_SIZE);

    clock_t start_time = clock();
    bubbleSort(arr, MAX_SIZE);
    clock_t end_time = clock();

    printf("Sorted array: \n");
    // Uncomment below line to enable printing sorted array
    //printArray(arr, MAX_SIZE);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Bubble sort for %d integers took %f seconds to complete.\n", MAX_SIZE, time_taken);

    return 0;
}
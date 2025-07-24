//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the array size
#define ARRAY_SIZE 1000000

// Define the array data type
typedef struct {
    int data[ARRAY_SIZE];
} ArrayData;

// Function declarations
void printArray(int *arr, int size);
void bubbleSort(int *arr, int size);
void quickSort(int *arr, int left, int right);
void swap(int *a, int *b);

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create an instance of the array data
    ArrayData arr_data;

    // Fill the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr_data.data[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted Array:\n");
    printArray(arr_data.data, ARRAY_SIZE);

    // Sort the array with bubble sort algorithm
    bubbleSort(arr_data.data, ARRAY_SIZE);

    // Print the array sorted by bubble sort
    printf("Sorted Array - Bubble Sort:\n");
    printArray(arr_data.data, ARRAY_SIZE);

    // Fill the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr_data.data[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted Array:\n");
    printArray(arr_data.data, ARRAY_SIZE);

    // Sort the array with quick sort algorithm
    quickSort(arr_data.data, 0, ARRAY_SIZE - 1);

    // Print the array sorted by quick sort
    printf("Sorted Array - Quick Sort:\n");
    printArray(arr_data.data, ARRAY_SIZE);

    return 0;
}

// Function to print an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort algorithm
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Quick Sort algorithm
void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot_index = left;
        int i = left + 1;
        int j = right;
        
        // Partition the array
        while (i <= j) {
            if (arr[i] <= arr[pivot_index]) {
                i++;
            }
            else if (arr[j] > arr[pivot_index]) {
                j--;
            }
            else {
                swap(&arr[i], &arr[j]);
            }
        }

        // Swap the pivot with the right index
        swap(&arr[pivot_index], &arr[j]);

        // Recurse for the left and right partitions
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
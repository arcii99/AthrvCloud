//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to initialize the array with random integers
void initializeArray(int *arr, int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand() % 1000; // Generating random numbers between 0 and 999
    }
}

// Function to print the array
void printArray(int *arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort algorithm
void bubbleSort(int *arr, int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Initializing the array with random integers
    initializeArray(arr, ARRAY_SIZE);

    // Printing the unsorted array
    printf("Unsorted Array: ");
    printArray(arr, ARRAY_SIZE);

    // Sorting the array using bubble sort algorithm
    bubbleSort(arr, ARRAY_SIZE);

    // Printing the sorted array
    printf("Sorted Array: ");
    printArray(arr, ARRAY_SIZE);

    return 0;
}
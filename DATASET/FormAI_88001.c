//FormAI DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to run the sorting algorithm
void sort(int arr[], int size) {
    // Loop through all elements in array
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in remaining unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        // Print the current state of the array after swapping
        printf("Current state of array after swapping %d and %d:\n", arr[i], arr[minIndex]);
        printArray(arr, size);
    }
}

int main() {
    // Initialize array
    int arr[10];
    srand(time(0));
    // Fill array with random numbers
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    // Print out the unsorted array
    printf("Unsorted Array:\n");
    printArray(arr, 10);
    // Run the sorting algorithm
    sort(arr, 10);
    // Print out the sorted array
    printf("Sorted Array:\n");
    printArray(arr, 10);
    return 0;
}
//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
// Let's sort some numbers, let's get energetic!
// This program will use quicksort to sort an array of numbers from smallest to largest
// Let's get right into it!

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Select the last element as the pivot
    int i = low - 1; // Initialize a smaller element index

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array and get pivot index
        quicksort(arr, low, pi - 1); // Sort the left partition
        quicksort(arr, pi + 1, high); // Sort the right partition
    }
}

int main() {
    // Let's create an array with random numbers
    int arr[10] = { 9, 7, 4, 5, 6, 3, 8, 2, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Let's sort these numbers!\n");

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    quicksort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Wow, what a rush! Let's do it again!\n");

    return 0;
}
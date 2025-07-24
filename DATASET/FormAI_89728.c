//FormAI DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>

// bubble sort algorithm to sort an array of integers
void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap two adjacent elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 0, 6}; // unsorted array
    int size = sizeof(arr) / sizeof(arr[0]); // calculate size of array

    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // perform bubble sort
    bubbleSort(arr, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
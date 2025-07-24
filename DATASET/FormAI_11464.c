//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    printf("Hello!\nLet's sort an array using Bubble Sort!\n\n");

    // Initialize an array
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, size);

    // Sort the array using Bubble Sort
    bubbleSort(arr, size);

    printf("\nSorted Array:\n");
    printArray(arr, size);

    printf("\nYay! We sorted an array using Bubble Sort!\n");

    return 0;
}
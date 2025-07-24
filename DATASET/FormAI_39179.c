//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort on an array of integers
void bubbleSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n-1; i++) {
        // Last i elements are already sorted, so we ignore them
        for (j = 0; j < n-i-1; j++) {
            // Swap adjacent elements if they are in wrong order
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
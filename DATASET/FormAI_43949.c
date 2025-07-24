//FormAI DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // choose last element as pivot
        int i = low - 1; // index of smaller element

        for (int j = low; j < high; j++) {
            // if current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]); // swap arr[i] and arr[j]
            }
        }
        swap(&arr[i + 1], &arr[high]); // swap pivot element and arr[i+1]

        // recursively sort left and right subarrays
        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

int main() {
    int arr[] = {50, 20, 40, 60, 10, 30};
    int n = 6;

    // display original array
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // perform quicksort
    quicksort(arr, 0, n - 1);

    // display sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
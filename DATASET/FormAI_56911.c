//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>

// A function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// A function to perform selection sort
void selectionSort(int arr[], int n) {

    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted array
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Print the array after each pass
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    printf("\nSorting in progress...\n\n");

    selectionSort(arr, n);

    printf("\nAfter Sorting: ");
    printArray(arr, n);

    return 0;
}
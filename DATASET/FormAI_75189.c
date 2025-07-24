//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>

// function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to perform bubble sort
void bubbleSort(int arr[], int n) {
    // loop through all elements
    for (int i = 0; i < n-1; i++) {
        // last i elements are already in place
        for (int j = 0; j < n-i-1; j++) {
            // if current element is greater than next element, swap them
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {4, 2, 1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nArray after sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform sorting
void sorting(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {25, 33, 11, 7, 45, 67, 22, 10, 19, 31};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Displaying the unsorted array
    printf("Unsorted Array: ");
    printArray(arr, size);

    // Sorting the array
    sorting(arr, size);

    // Displaying the sorted array
    printf("Sorted Array: ");
    printArray(arr, size);

    return 0;
}
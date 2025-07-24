//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE];
    int searchKey = 6;

    // Randomly populate array with integers
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 10;

    // Sort array in ascending order
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print original array
    printf("Original Array: ");
    printArray(arr, SIZE);

    // Perform binary search and print result
    int result = binarySearch(arr, 0, SIZE - 1, searchKey);
    if (result == -1)
        printf("%d not found in array\n", searchKey);
    else
        printf("%d found at index %d\n", searchKey, result);

    return 0;
}
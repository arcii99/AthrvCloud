//FormAI DATASET v1.0 Category: Searching algorithm ; Style: intelligent
/*
 * This program performs a unique searching algorithm using binary search technique
 * to find a particular element from an array of integers.
 * The array must be sorted in ascending order before executing this program.
 *
 * Author: [Your Name]
 * Date: [Date of completion]
 */

#include <stdio.h>

// Function prototypes
int binarySearch(int arr[], int first, int last, int element);
void printArray(int arr[], int size);

// Main function
int main() {
    int arr[] = {2, 4, 6, 7, 8, 9, 10, 11, 12, 14, 16, 17, 19, 20, 23, 26, 28, 29, 31, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search_element = 14;

    printf("The original array: ");
    printArray(arr, size);

    // Perform the binary search
    int result = binarySearch(arr, 0, size - 1, search_element);

    // Check whether the element is found or not
    if (result == -1) {
        printf("\nThe element %d is not found in the array.\n", search_element);
    } else {
        printf("\nThe element %d is found at index %d in the array.\n", search_element, result);
    }

    return 0;
}

// This function performs binary search on the given array
int binarySearch(int arr[], int first, int last, int element) {
    // Base case
    if (first > last) {
        return -1;  // Element not found
    }

    // Calculate mid index of the array
    int mid = (first + last) / 2;

    // Check whether the mid element is the search element
    if (arr[mid] == element) {
        return mid;  // Element found
    }

    // If mid element is less than the search element,
    // search in the right half of the array
    if (arr[mid] < element) {
        return binarySearch(arr, mid + 1, last, element);
    }

    // If mid element is greater than the search element,
    // search in the left half of the array.
    return binarySearch(arr, first, mid - 1, element);
}

// This function prints the given array
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
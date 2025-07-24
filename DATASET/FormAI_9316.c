//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
/* This is a custom searching algorithm that uses a combination of linear search and binary search to find the position of a key in an array.
 * The program first checks if the key is present in the arrays by doing a linear search. If it is not found, the program
 * then performs a binary search on a sub-array of the original array containing elements that are greater than the key. If the key
 * is found in the binary sub-array search, the position of the key in the original array is returned. If not, the program
 * returns -1 indicating that the key is not present in the array.
 */

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key);
int customSearch(int arr[], int size, int key);
void printArray(int arr[], int size);

int main(void) {
    int arr[] = {10, 16, 20, 32, 45, 56, 60, 68, 72, 89, 100};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int key = 68;

    printf("Original Array:\n");
    printArray(arr, arr_size);
    printf("\n");

    int result = customSearch(arr, arr_size, key);

    if (result == -1) {
        printf("Element not found in array.\n");
    } else {
        printf("Element found at position %d in array.\n", result);
    }

    return 0;
}

int customSearch(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // return index of key if found
        } else if (arr[i] > key) {
            break; // break if current element is greater than key
        }
    }

    // perform binary search on sub-array of elements greater than key
    return binarySearch(arr, i, size - 1, key);
}

/* Recursive implementation of binary search. */
int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left)/2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        } else {
            return binarySearch(arr, mid + 1, right, key);
        }
    }

    // key not found in sub-array
    return -1;
}

/* Utility function to print an array. */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
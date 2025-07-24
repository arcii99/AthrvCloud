//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

// function to perform binary search recursively
int binarySearchRecursive(int arr[], int low, int high, int num) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num) {
            return mid;
        }
        else if (arr[mid] < num) {
            return binarySearchRecursive(arr, mid + 1, high, num);
        }
        else {
            return binarySearchRecursive(arr, low, mid - 1, num);
        }
    }
    return -1; // element not found
}

// function to perform binary search iteratively
int binarySearchIterative(int arr[], int low, int high, int num) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num) {
            return mid;
        }
        else if (arr[mid] < num) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // element not found
}

// main function
int main() {
    int arr[] = { 1, 3, 5, 7, 8, 9, 11, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 9;

    // Calling binary search recursively
    int index = binarySearchRecursive(arr, 0, n - 1, num);
    if (index == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index: %d\n", index);
    }

    // Calling binary search iteratively
    index = binarySearchIterative(arr, 0, n - 1, num);
    if (index == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index: %d\n", index);
    }

    return 0;
}
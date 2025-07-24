//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>

int paranoidSearch(int arr[], int size, int target) {
    // Step 1: Check if array is empty
    if (size <= 0) {
        // Raise an exception, there's some fishy activity going on
        fprintf(stderr, "ERROR: Attempted to search an empty array!\n");
        exit(1);
    }

    // Step 2: Check if target is within the bounds of the array
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }
    if (target < min || target > max) {
        // Raise another exception, we can never be too careful
        fprintf(stderr, "ERROR: Attempted to search for a target outside of the array's bounds!\n");
        exit(1);
    }

    // Step 3: Search for the target using iteration, but keep an eye out for any fishy activity
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        // Check if low and high are still within bounds
        if (low < 0 || low >= size || high < 0 || high >= size) {
            // Print a warning message to the console, just in case
            printf("WARNING: Something fishy is going on with the low and high indices.\n");
            printf("         Low: %d, High: %d\n", low, high);
        }

        // Check if low and high have converged
        if (low == high && arr[low] != target) {
            // Raise yet another exception, since we don't trust the input anymore
            fprintf(stderr, "ERROR: Target not found!\n");
            exit(1);
        }
    }

    // We should never get to this point, but just in case...
    fprintf(stderr, "ERROR: Something went wrong!\n");
    exit(1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);

    int target1 = 4;
    int target2 = 10;
    int target3 = 0;

    int index1 = paranoidSearch(arr, size, target1);
    int index2 = paranoidSearch(arr, size, target2);
    int index3 = paranoidSearch(arr, size, target3);

    printf("Target 1 found at index %d\n", index1);
    printf("Target 2 found at index %d\n", index2);
    printf("Target 3 found at index %d\n", index3);

    return 0;
}
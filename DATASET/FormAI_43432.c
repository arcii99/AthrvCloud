//FormAI DATASET v1.0 Category: Searching algorithm ; Style: bold
#include <stdio.h>
#include <stdlib.h>

// C searching algorithm example program

int linear_search(int arr[], int n, int target) {
    // Linear search algorithm
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int target) {
    // Binary search algorithm
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    // Initializing an array and target value for search
    int arr[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int target = 12;

    // Performing linear search and displaying the result
    int linear_index = linear_search(arr, 10, target);
    if (linear_index != -1) {
        printf("Linear Search Result: Found at index %d\n", linear_index);
    }
    else {
        printf("Linear Search Result: Not found\n");
    }

    // Performing binary search and displaying the result
    int binary_index = binary_search(arr, 10, target);
    if (binary_index != -1) {
        printf("Binary Search Result: Found at index %d\n", binary_index);
    }
    else {
        printf("Binary Search Result: Not found\n");
    }

    return 0;
}
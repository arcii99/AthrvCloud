//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

// Function to perform binary search on an array
int binary_search(int arr[], int n, int target) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Perform binary search on the array
    int result = binary_search(arr, n, target);

    // Print the result of the search
    if (result != -1) {
        printf("The target element %d was found at index %d.\n", target, result);
    } else {
        printf("The target element %d was not found in the array.\n", target);
    }

    return 0;
}
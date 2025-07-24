//FormAI DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int result = binary_search(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element not found using binary search\n");
    } else {
        printf("Element found at index %d using binary search\n", result);
    }

    result = linear_search(arr, n, target);
    if (result == -1) {
        printf("Element not found using linear search\n");
    } else {
        printf("Element found at index %d using linear search\n", result);
    }

    return 0;
}
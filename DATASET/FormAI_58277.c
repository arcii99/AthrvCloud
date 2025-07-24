//FormAI DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>

// This program is an implementation of a unique searching algorithm
// that combines linear and binary search techniques

int search(int arr[], int n, int x) {

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If the element is not found by binary search, switch to linear search
    for (int i = left; i <= right; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int main() {

    int arr[] = {3, 6, 8, 11, 14, 18, 19, 21, 24, 26, 29, 33, 36, 38, 41, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 29;

    int result = search(arr, n, x);

    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}
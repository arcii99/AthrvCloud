//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>

// Linear search algorithm
int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary search algorithm
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 23;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("%d not found in the array\n", x);
    } else {
        printf("%d found at index %d using linear search\n", x, result);
    }

    x = 38;
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        printf("%d not found in the array\n", x);
    } else {
        printf("%d found at index %d using binary search\n", x, result);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search recursively
int binarySearchRecursive(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearchRecursive(arr, l, mid - 1, x);
        }

        return binarySearchRecursive(arr, mid + 1, r, x);
    }

    return -1;
}

// Function to perform binary search iteratively
int binarySearchIterative(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Perform linear search
    int x = 10;
    int index = linearSearch(arr, n, x);
    if (index == -1) {
        printf("%d not found in the array", x);
    } else {
        printf("%d found at index %d", x, index);
    }

    // Perform binary search recursively
    x = 3;
    index = binarySearchRecursive(arr, 0, n - 1, x);
    if (index == -1) {
        printf("\n%d not found in the array", x);
    } else {
        printf("\n%d found at index %d", x, index);
    }

    // Perform binary search iteratively
    x = 40;
    index = binarySearchIterative(arr, 0, n - 1, x);
    if (index == -1) {
        printf("\n%d not found in the array", x);
    } else {
        printf("\n%d found at index %d", x, index);
    }

    return 0;
}
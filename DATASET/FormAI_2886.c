//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x);

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
    }

    return binarySearch(arr, i/2, i, x);
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 9, 11, 15, 16, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    int result = exponentialSearch(arr, n, x);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
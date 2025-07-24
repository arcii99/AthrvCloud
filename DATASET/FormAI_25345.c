//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>

int search(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int result = search(arr, 0, n - 1, key);
    if (result == -1) {
        printf("%d is not present in the array\n", key);
    } else {
        printf("%d is present at index %d\n", key, result);
    }

    key = 7;
    result = search(arr, 0, n - 1, key);
    if (result == -1) {
        printf("%d is not present in the array\n", key);
    } else {
        printf("%d is present at index %d\n", key, result);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(int);
    int target = 9;

    int result = binary_search(arr, size, target);

    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", result);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

int search(int arr[], int n, int key);

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = search(arr, n, key);

    if (result == -1) {
        printf("Element is not present in array.\n");
    } else {
        printf("Element is present at index %d.\n", result);
    }

    return 0;
}

int search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#define SIZE 10

int binarySearch(int arr[], int low, int high, int key);

int main() {
    int arr[SIZE] = {2, 3, 4, 6, 8, 10, 12, 14, 16, 18};
    int key = 10;
    int index = binarySearch(arr, 0, SIZE - 1, key);

    if (index == -1) {
        printf("The key was not found\n");
    } else {
        printf("The key was found at index %d\n", index);
    }

    return 0;
}

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, high, key);
    }

    return -1;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        return binarySearch(arr, mid + 1, right, key);
    }

    return -1;
}

int main(void) {
    int arr[] = {2, 5, 8, 20, 25, 30, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;
    int result = binarySearch(arr, 0, n - 1, key);

    (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);

    return 0;
}
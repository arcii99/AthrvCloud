//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int binarySearch(int arr[], int start, int end, int elem) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == elem) {
            return mid;
        }

        if (arr[mid] > elem) {
            return binarySearch(arr, start, mid - 1, elem);
        }

        return binarySearch(arr, mid + 1, end, elem);
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 9, 12, 25, 28, 32, 35, 42};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 12;
    int result = binarySearch(arr, 0, n - 1, x);
    printf("The element %d is found at index %d", x, result);

    return 0;
}
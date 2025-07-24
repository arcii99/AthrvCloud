//FormAI DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>

int search(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 11, 18, 22, 27, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;

    int result = search(arr, n, x);

    if (result == -1) {
        printf("Element not found in array.");
    }
    else {
        printf("Element found at index %d.", result);
    }

    return 0;
}
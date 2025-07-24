//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>

// Custom searching algorithm inspired by Ken Thompson
int ken_search(int *arr, int n, int target) {
    int start = 0, end = n - 1;
    int mid;

    while (start <= end) {
        mid = (end + start) / 2;

        if (arr[mid] == target) {
            return mid; // we found the target
        }

        if (arr[start] <= arr[mid]) { // left side is sorted
            if (target >= arr[start] && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (arr[mid] <= arr[end]) { // right side is sorted
            if (target > arr[mid] && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1; // target not found
}

int main() {
    int arr[] = {5, 7, 10, 13, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int target = 7;

    int index = ken_search(arr, n, target);

    if (index == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", index);
    }

    return 0;
}
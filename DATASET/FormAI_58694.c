//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Target not found in array
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    int index = binary_search(arr, 0, 9, target);

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found in array\n");
    }

    return 0;
}
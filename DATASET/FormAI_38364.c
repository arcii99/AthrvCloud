//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    // While left index is less than or equal to right index
    while (left <= right) {
        // Middle index of the array
        int mid = left + (right - left) / 2;

        // If target is present at the middle
        if (arr[mid] == target)
            return mid;

        // If target is greater than middle element, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller than middle element, ignore right half
        else
            right = mid - 1;
    }

    // Target is not present in the array
    return -1;
}

int main() {
    // Sorted array to search a target from
    int arr[] = {2, 5, 10, 22, 32, 45, 56, 70, 85, 92};
    int target = 32;
    int arrLen = sizeof(arr) / sizeof(arr[0]);

    // Searching the target in the array using binary search
    int resultIndex = binarySearch(arr, 0, arrLen - 1, target);

    // Display the result
    if (resultIndex == -1)
        printf("Target is not present in the array.");
    else
        printf("Target is present at index %d.", resultIndex);

    return 0;
}
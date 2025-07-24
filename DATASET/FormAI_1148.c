//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    // Check if the target is within the bounds of the array
    if (low <= high) {
        int mid = (low + high) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid;
        }

        // Recursive binary search on the left half of the array
        if (arr[mid] > target) {
            return binary_search(arr, low, mid - 1, target);
        }

        // Recursive binary search on the right half of the array
        return binary_search(arr, mid + 1, high, target);
    }

    // Target not found in array
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_elements = sizeof(nums) / sizeof(int);

    // Find index of target 5
    int target = 5;
    int index = binary_search(nums, 0, num_elements - 1, target);

    if (index != -1) {
        printf("Target %d found at index %d\n", target, index);
    } else {
        printf("Target %d not found in array\n", target);
    }

    // Find index of target 11
    target = 11;
    index = binary_search(nums, 0, num_elements - 1, target);

    if (index != -1) {
        printf("Target %d found at index %d\n", target, index);
    } else {
        printf("Target %d not found in array\n", target);
    }

    return 0;
}
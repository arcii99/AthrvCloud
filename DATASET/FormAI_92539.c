//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>

int unique_Search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int mid;

    // loop until the left pointer is less than or equal to the right pointer
    while (left <= right) {
        mid = (left + right) / 2;

        // If target is found
        if (arr[mid] == target)
            return mid;

        // Check if the left side of the middle element is sorted
        if (arr[left] <= arr[mid]) {
            // Check if the target is within the sorted left side of the array
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            // If target is not on the left side of the array, search the right side
            else
                left = mid + 1;
        }

        // Check if the right side of the middle element is sorted
        else {
            // Check if the target is within the sorted right side of the array
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            // If target is not on the right side of the array, search the left side
            else
                right = mid - 1;
        }
    }
    // If the element is not found, return -1
    return -1;
}

int main() {
    int arr[] = { 10, 12, 15, 17, 2, 4, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;
    int index = unique_Search(arr, n, target);
    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d is not found.\n", target);
    }

    return 0;
}
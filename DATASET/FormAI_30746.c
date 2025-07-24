//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>

int search(int arr[], int n, int x) {
    // Multi-variable approach
    int left = 0, right = n - 1;  // Define left and right pointers
    int mid; // Define mid index variable

    while (left <= right) {  // Search the array while left is less than or equal to right
        mid = left + (right - left) / 2;  // Calculate the mid index
        if (arr[mid] == x) {  // Check if x is present at mid
            return mid;  // Return the mid index
        }
        else if (arr[mid] < x) {  // If x is greater, ignore left half
            left = mid + 1;
        }
        else {  // If x is smaller, ignore right half
            right = mid - 1;
        }
    }

    return -1;  // If we reach here, then element was not present in the array
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = search(arr, n, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}
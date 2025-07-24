//FormAI DATASET v1.0 Category: Searching algorithm ; Style: bold
#include <stdio.h>

/* This program is a unique searching algorithm that takes an integer array and
 * a target value, and returns the index of the target value in the array if it
 * exists, or -1 if it does not. The algorithm works by dividing the array in 
 * half repeatedly until the target value is found, or until there are no more
 * elements to search. This algorithm is called binary search.
 */

int binary_search(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; // target not found
    }

    int mid = (left + right) / 2; // find the middle index
    if (arr[mid] == target) {
        return mid; // target found!
    } else if (arr[mid] < target) {
        return binary_search(arr, target, mid+1, right); // search the right half
    } else {
        return binary_search(arr, target, left, mid-1); // search the left half
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binary_search(arr, target, 0, n-1);
    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", result);
    }

    return 0;
}
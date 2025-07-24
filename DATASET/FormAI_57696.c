//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
/*
 * This is a unique searching algorithm that utilizes a genius approach to find the target element.
 * Instead of searching through the array linearly, it employs a divide and conquer strategy.
 * The algorithm first checks the middle element of the array and compares it to the target.
 * If the middle element is greater than the target, the left half of the array is searched recursively.
 * If the middle element is less than the target, the right half of the array is searched recursively.
 * This process is repeated until the target element is found or it is determined that the target is not in the array.
 */

#include <stdio.h>

int binary_search(int arr[], int start, int end, int target) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target && start <= end) {
        return binary_search(arr, start, mid - 1, target);
    } else if (arr[mid] < target && start <= end) {
        return binary_search(arr, mid + 1, end, target);
    } else {
        return -1;
    }
}

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int result = binary_search(arr, 0, size - 1, target);
    
    if (result == -1) {
        printf("Target not found in array\n");
    } else {
        printf("Target found at index %d\n", result);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>

// binary search function
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) { // base case: target not found
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) { // target found
        return mid;
    } 
    else if (arr[mid] < target) { // target may be in right half
        return binarySearch(arr, mid + 1, high, target);
    }
    else { // target may be in left half
        return binarySearch(arr, low, mid - 1, target);
    }
}

int main() {
    int n, target;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements (in sorted order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter target element to be searched: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Target element not found!\n");
    } else {
        printf("Target element found at index %d\n", result);
    }
    return 0;
}
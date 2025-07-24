//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>

int linear_search(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int interpolation_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
 
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = linear_search(arr, n, target);
    printf("Linear Search:\n");
    if (result == -1) {
        printf("Target element is not present in array.\n");
    } else {
        printf("Target element is present at index %d.\n", result);
    }
    result = binary_search(arr, 0, n - 1, target);
    printf("Binary Search:\n");
    if (result == -1) {
        printf("Target element is not present in array.\n");
    } else {
        printf("Target element is present at index %d.\n", result);
    }
    result = interpolation_search(arr, n, target);
    printf("Interpolation Search:\n");
    if (result == -1) {
        printf("Target element is not present in array.\n");
    } else {
        printf("Target element is present at index %d.\n", result);
    }   
    return 0;
}
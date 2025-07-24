//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 10, 14, 17, 20};
    int target = 17;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, 0, n - 1, target);
    
    if (index != -1) {
        printf("%d found at index %d\n", target, index);
    }
    else {
        printf("%d not found in the array\n", target);
    }
    
    return 0;
}
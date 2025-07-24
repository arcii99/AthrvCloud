//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;
    int result = binarySearch(arr, 0, 9, target);
    
    if (result == -1) {
        printf("Target not found in array\n");
    } else {
        printf("Target found at index: %d\n", result);
    }
    
    return 0;
}
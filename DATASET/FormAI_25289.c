//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

// The Brave Binary Search function
int braveBinarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            return braveBinarySearch(arr, left, mid - 1, target);
        }
        
        return braveBinarySearch(arr, mid + 1, right, target);
    }
    
    return -1;
}

// Main function for testing
int main() {
    int arr[10] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(int);
    int target = 60;
    int result = braveBinarySearch(arr, 0, n - 1, target);
    
    if (result == -1) {
        printf("Sorry, target not found in the array.");
    } else {
        printf("Brave Binary Search found target %d at index %d.", target, result);
    }
    
    return 0;
}
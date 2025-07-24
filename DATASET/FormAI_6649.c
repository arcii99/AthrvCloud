//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

// define function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    
    int index = binary_search(arr, size, target);
    
    if (index != -1) {
        printf("%d found at index %d\n", target, index);
    } else {
        printf("%d not found in array\n", target);
    }
    
    return 0;
}
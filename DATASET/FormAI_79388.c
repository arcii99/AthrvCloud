//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

int BinarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);
        
        return BinarySearch(arr, mid + 1, r, x);
    }
    
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = BinarySearch(arr, 0, n - 1, x);
    
    if (result == -1)
        printf("Element is not present in array.");
    else
        printf("Element is present at index %d.", result);
    
    return 0;
}
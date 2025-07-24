//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

int search(int arr[], int n, int x) {
    // Initialize lower and upper bounds.
    int l = 0, r = n - 1;
 
    // Iterate while l <= r
    while (l <= r) {
        // Calculate mid position.
        int mid = (l + r) / 2;
 
        // If element is present at mid, return mid.
        if (arr[mid] == x)
            return mid;
 
        // If arr[mid] < x, then the element is in the right subarray.
        if (arr[mid] < x)
            l = mid + 1;
 
        // Else the element is in the left subarray.
        else
            r = mid - 1;
    }
 
    // else return -1
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = search(arr, n, x);
    if (result == -1)
        printf("Element is not present in array.\n");
    else
        printf("Element is present at index %d.\n", result);
    return 0;
}
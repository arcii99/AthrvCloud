//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

// Function to implement binary search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not present in array
    return -1;
}

// Main function
int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, x);
    
    // Print result
    if (result == -1) {
        printf("The element was not found in the array.\n");
    } else {
        printf("The element was found at index %d in the array.\n", result);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int l, int r, int x) {
    
    while (l <= r) {
        int m = l + (r-l)/2;
        
        // Check if x is present at mid
        if (arr[m] == x) {
            return m;
        }
        
        // If x greater, ignore left half
        if (arr[m] < x) {
            l = m + 1;
        }
        
        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }
    
    // If we reached here, then element was not present
    return -1;
}

int main() {
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int n = sizeof(arr)/sizeof(arr[0]);
     int x = 7;
     int result = binary_search(arr, 0, n-1, x);
     if (result == -1) {
         printf("Surprise! The number %d was not found in the array\n", x);
     } else {
         printf("Congratulations! The number %d was found at position %d in the array\n", x, result);
     }
     return 0;
}
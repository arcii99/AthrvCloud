//FormAI DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>

/* Number of elements in the array */
#define N 10

/* Function to perform binary search on a sorted array */
int binary_search(int arr[], int low, int high, int target) {
    int mid;
    
    /* Loop until low is less than or equal to high */
    while (low <= high) {
        
        /* Calculate the mid index */
        mid = (low + high) / 2;
        
        /* If the target is found, return its index */
        if (arr[mid] == target) {
            return mid;
        }
        
        /* If the target is less than the mid element, search the left half */
        if (arr[mid] > target) {
            high = mid - 1;
        }
        
        /* If the target is greater than the mid element, search the right half */
        else {
            low = mid + 1;
        }
    }
    
    /* If the target is not found, return -1 */
    return -1;
}

int main() {
    
    /* Sorted array */
    int arr[N] = {1, 3, 4, 6, 7, 8, 9, 11, 12, 14};
    
    /* Target to search for */
    int target = 6;
    
    /* Perform binary search */
    int result = binary_search(arr, 0, N - 1, target);
    
    /* Print the result */
    if (result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", result);
    }
    
    return 0;
}
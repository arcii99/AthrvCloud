//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

/**
 * A custom searching algorithm to find the index of the
 * first occurrence of a given integer in a sorted array
 * 
 * @param arr the sorted integer array
 * @param n the size of the array
 * @param x the integer to search for
 * @return the index of the first occurrence of x, -1 if not found
 */
int custom_search(int arr[], int n, int x) {
    int left = 0, right = n - 1, mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        // if x is found, check if it's the first occurrence
        if (arr[mid] == x) {
            // check if it's the first occurrence
            while (mid > 0 && arr[mid - 1] == x) {
                mid--;
            }
            return mid;
        }

        // search the left half if x is smaller than arr[mid]
        if (x < arr[mid]) {
            right = mid - 1;
        }
        
        // search the right half if x is larger than arr[mid]
        else {
            left = mid + 1;
        }
    }

    // x was not found, return -1
    return -1;
}

int main() {
    // example usage
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = custom_search(arr, n, x);
    
    if (index != -1) {
        printf("%d was found at index %d\n", x, index);
    }
    else {
        printf("%d was not found\n", x);
    }

    return 0;
}
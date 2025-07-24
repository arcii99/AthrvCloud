//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

// A function to perform a linear search
int linearSearch(int arr[], int n, int target) {
    // starting from the first element, check each element one by one
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i; // return index of the target element
        }
    }
    return -1; // if target element is not found in the array
}

// A function to perform a binary search
int binarySearch(int arr[], int l, int r, int target) {
    if(r >= 1) {
        int mid = l + (r - l) / 2; // calculate middle index
        if(arr[mid] == target) {
            return mid; // return index of target element
        }
        if(arr[mid] > target) {
            return binarySearch(arr, l, mid-1, target); // search in left half
        }
        return binarySearch(arr, mid+1, r, target); // search in right half
    }
    return -1; // if target element is not found in the array
}

int main() {
    int arr[] = {2, 4, 3, 6, 8, 7, 1, 5}; // declare an array
    int n = sizeof(arr) / sizeof(arr[0]); // calculate size of the array
    int target = 7; // declare the target element to search for
    
    printf("Performing a linear search to find target element %d\n", target);
    int result1 = linearSearch(arr, n, target); // call linear search function
    if(result1 == -1) {
        printf("Target element not found in the array\n"); // if target is not found
    }
    else {
        printf("Target element found at index %d\n", result1); // if target is found
    }
    
    printf("Performing a binary search to find target element %d\n", target);
    int result2 = binarySearch(arr, 0, n-1, target); // call binary search function
    if(result2 == -1) {
        printf("Target element not found in the array\n"); // if target is not found
    }
    else {
        printf("Target element found at index %d\n", result2); // if target is found
    }
    
    return 0;
}
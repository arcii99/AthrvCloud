//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>

//function for linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; //return the index of the element if found
        }
    }
    return -1; //return -1 if element not found
}

//function for binary search
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
 
        if (arr[mid] == x) {
            return mid; //return the index of the element if found
        }

        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x); //recurse on left half of the array
        }
 
        return binarySearch(arr, mid + 1, right, x); //recurse on right half of the array
    }

    return -1; //return -1 if element not found
}

//driver code
int main() {
    int arr[] = { 2, 4, 9, 12, 22, 35, 41, 57, 63, 78 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22; //element to be searched

    int result = linearSearch(arr, n, x); //perform linear search

    if (result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", result);
    }

    result = binarySearch(arr, 0, n - 1, x); //perform binary search

    if (result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
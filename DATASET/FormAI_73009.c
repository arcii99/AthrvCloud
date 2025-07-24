//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

// function that searches an integer in a given array
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // if the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // if the element is smaller than mid, then it can only be present in the left subarray
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        // else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, right, x);
    }

    // if the element is not present in the array
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // call the binarySearch function to search for the element
    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}
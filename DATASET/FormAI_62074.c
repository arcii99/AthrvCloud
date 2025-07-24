//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include<stdio.h>

/* This is a program to implement Binary Search Algorithm using C */

int binarySearch(int arr[], int left, int right, int key);

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Data to be searched
    int key = 23; // Key value to be searched in the array
    int n = sizeof(arr)/sizeof(arr[0]); // Size of the array
    int result = binarySearch(arr, 0, n-1, key); // Call binarySearch function
    if(result == -1)
        printf("The element is not present in the array");
    else
        printf("The element is present at index %d", result);
    return 0;
}

int binarySearch(int arr[], int left, int right, int key)
{
    if (right >= left) {
        int mid = left + (right - left) / 2; // Calculating middle index of the array

        // If the element is present at the middle
        if (arr[mid] == key)
            return mid;

        // If element is smaller than middle
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Else the element is present in right subarray
        return binarySearch(arr, mid + 1, right, key);
    }
    // Element is not present in the array
    return -1;
}
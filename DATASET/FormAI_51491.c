//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

//function to perform binary search recursively
int binarySearch(int arr[], int low, int high, int target)
{
    //base case
    if (high < low)
        return -1;

    //calculate mid index
    int mid = low + (high - low) / 2;

    //if target is found at mid index
    if (arr[mid] == target)
        return mid;

    //if target is smaller than arr[mid] then search in left half
    if (arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target);

    //else search in right half
    return binarySearch(arr, mid + 1, high, target);
}

int main()
{
    //declaring an array of integers
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    
    //calculate the size of array
    int size = sizeof(arr) / sizeof(arr[0]);

    //declaring the target value for searching
    int target = 10;

    //performing binary search
    int result = binarySearch(arr, 0, size - 1, target);

    //checking if the target is found or not
    if (result == -1)
        printf("Target not found in the array.");
    else
        printf("Target found at index %d.", result);

    return 0;
}
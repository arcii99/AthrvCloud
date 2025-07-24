//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int retroSearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right) 
    {
        // Find the mid element of the array
        int mid = left + (right - left) / 2;

        // If element is present at mid, return its index
        if (arr[mid] == x)
            return mid;
        
        // If the left subarray is sorted
        if (arr[left] < arr[mid])
        {
            // Check if x is present in the left subarray
            if (arr[left] <= x && x < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // If the right subarray is sorted
        else
        {
            // Check if x is present in the right subarray
            if (arr[mid] <= x && x < arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    // If element is not present in array
    return -1;
}

int main()
{
    int arr[] = {56, 78, 90, 10, 37, 41, 49};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 41;
    // Call the retroSearch function
    int result = retroSearch(arr, n, x);
    // If element is present in the array
    if (result != -1)
        printf("Element %d is present at index %d", x, result);
    else
        printf("Element %d is not present", x);
    return 0;
}
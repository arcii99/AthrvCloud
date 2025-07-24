//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int paranoidSearch(int arr[], int n, int x);

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sample array to search for in the paranoid way
    int x = 8; // Value to search for
    int n = sizeof(arr)/sizeof(arr[0]); // Length of the array
    int index = paranoidSearch(arr, n, x); // Calling the paranoid search function
    
    if(index == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element found at index %d\n", index);
    }
    
    return 0;
}

int paranoidSearch(int arr[], int n, int x)
{
    int i = 0;
    int j = n - 1;
    
    while(i <= j)
    {
        int mid = (i + j) / 2;
        
        // Check if the element is found at the middle itself
        if(arr[mid] == x)
        {
            return mid;
        }
        
        // Check if the left half of the array is sorted
        if(arr[i] <= arr[mid])
        {
            // Check if the element lies within the left half
            if(x >= arr[i] && x < arr[mid])
            {
                j = mid - 1;
            }
            // Otherwise, search the right half of the array
            else
            {
                i = mid + 1;
            }
        }
        // Otherwise, the right half of the array is sorted
        else
        {
            // Check if the element lies within the right half
            if(x > arr[mid] && x <= arr[j])
            {
                i = mid + 1;
            }
            // Otherwise, search the left half of the array
            else
            {
                j = mid - 1;
            }
        }
    }
    
    // If the element is not found, return -1
    return -1;
}
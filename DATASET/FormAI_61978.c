//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>

// Use a macro to define the array size
#define ARRAY_SIZE 10

// Function to perform the binary search
int binary_search(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
  
        // Check if x is at mid
        if (arr[mid] == x) 
            return mid;
  
        // If x is greater, ignore left half
        if (arr[mid] < x) 
            low = mid + 1;
  
        // If x is smaller, ignore right half
        else 
            high = mid - 1;
    }
  
    // If we reach here, element was not present
    return -1;
}

// Main function to test the binary search
int main()
{
    int arr[ARRAY_SIZE] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int x = 14;
    int result = binary_search(arr, 0, ARRAY_SIZE - 1, x);

    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
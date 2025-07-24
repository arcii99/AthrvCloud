//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to perform a binary search in a given array
int binary_search(int arr[], int low, int high, int key)
{
    // Continue searching while the high index is greater than the low index
    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        // Check if the middle element is the key we are searching for
        if (arr[mid] == key)
        {
            return mid;
        }

        // If the middle element is greater than the key, search the left side of the array
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
        // Otherwise, search the right side of the array
        else
        {
            low = mid + 1;
        }
    }

    // If the key is not found, return -1
    return -1;
}

int main()
{
    int arr[] = { 2, 4, 6, 8, 10, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    // Perform binary search on the array
    int result = binary_search(arr, 0, n - 1, key);

    // Output whether or not the key was found in the array
    if (result == -1)
    {
        printf("The key was not found in the array.\n");
    }
    else
    {
        printf("The key was found at index %d.\n", result);
    }

    return 0;
}
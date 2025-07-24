//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include<stdio.h>

// Function that implements the searching algorithm
int search(int arr[], int n, int x)
{
    // Start from the first element in the array
    int i = 0;

    // Loop through the entire array
    for (i = 0; i < n; i++)
    {
        // Check if the current element is equal to x
        if (arr[i] == x)
        {
            // Return the index of the element
            return i;
        }
    }

    // Return -1 if the element is not found
    return -1;
}

// Main function for executing the program
int main()
{
    // Declare an array of integers and initialize it
    int arr[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the search function to search for an element
    int result = search(arr, n, 15);

    // Check if the element was found or not
    if (result == -1)
    {
        printf("Element not found in the array.\n");
    }
    else
    {
        printf("Element found at index %d in the array.\n", result);
    }

    return 0;
}
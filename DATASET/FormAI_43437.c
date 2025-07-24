//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

/* Function to search for element in the array */
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i; // Return the index of the element
        }
    }
    return -1; // If element is not found, return -1
}

int main()
{
    int arr[] = {2, 6, 8, 12, 15, 18, 21, 25, 29, 31}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of array
    int x = 21; // Element to search for
    int result = search(arr, n, x); 

    if (result == -1)
    {
        printf("%d is not present in the array\n", x);
    }
    else
    {
        printf("%d is present at index %d in the array\n", x, result);
    }
    return 0;
}
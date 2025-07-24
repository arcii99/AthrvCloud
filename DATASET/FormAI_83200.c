//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include<stdio.h>

// User-defined function to search an element in the array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Main function
int main()
{
    int arr[] = { 2, 4, 6, 8, 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // Calling the search function for the element
    int result = search(arr, n, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n", result);
    return 0;
}
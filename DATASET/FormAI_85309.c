//FormAI DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>

// Function to perform searching
int linearSearch(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;

    // Performing linear search on the array
    int index = linearSearch(arr, n, x);

    if(index == -1)
        printf("Element not found in the array\n");
    else
        printf("Element %d found at index %d\n", x, index);

    return 0;
}
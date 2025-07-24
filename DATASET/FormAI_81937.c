//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

// Function to search for an integer element in an array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
  
        // If element found at index i, return index i
        if (arr[i] == x)
            return i;
    }
  
    // If element not found, return -1
    return -1;
}

int main()
{
    int n, x, result;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Function Call
    result = search(arr, n, x);

    if(result == -1)
        printf("Element not found in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
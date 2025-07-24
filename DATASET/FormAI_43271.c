//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include<stdio.h>

// Function to search an element using sentinel linear search algorithm
int sentinelLinearSearch(int arr[], int n, int x)
{
    // Store the last element of the array
    int last = arr[n-1];
 
    // Set the last element as the sentinel value
    arr[n-1] = x;
 
    // Start the linear search
    int i = 0;
    while (arr[i] != x)
    {
        i++;
    }
 
    // Revert the last element back to its original value
    arr[n-1] = last;
 
    // If the element is found and not the last element
    if ((i < n-1) || (x == arr[n-1]))
    {
        return i;
    }
    else
    {
        return -1;
    }
}

// Main function to test the sentinel linear search algorithm
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;

    printf("Original array: ");
    for(int i=0; i<n; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");

    int result = sentinelLinearSearch(arr, n, x);
    if (result == -1)
    {
        printf("Element is not present in the array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to search for an element in an array using Linear Search Algorithm
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;   // Return the index of the element if it is found
    }
    return -1;  // If element is not found, return -1
}

int main()
{
    int arr[] = {5, 10, 50, 23, 99};   // Array to be searched
    int n = sizeof(arr)/sizeof(arr[0]); // Find the length of the array
    int x = 23; // Element to be searched

    printf("The original array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);  // Print the original array
    }
    printf("\n");

    int index = linearSearch(arr, n, x);    // Search for the element using Linear Search Algorithm

    if (index == -1)    // If element is not found
    {
        printf("Sorry, the element %d is not found in the array", x);
    }
    else    // If element is found
    {
        printf("%d is found at index %d in the array", x, index);
    }

    return 0;   // Terminate the program
}
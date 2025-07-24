//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
// Hello there! Welcome to my sorting program.
// This program takes in an array of integers and sorts them using the bubble sort algorithm.
// Let's get started!

#include <stdio.h>

int main()
{
    int arr[] = {23, 12, 56, 44, 78, 33}; // Let's define our array
    int n = sizeof(arr)/sizeof(arr[0]); // Calculate the size of the array

    // Let's print out the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Time to sort the array using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Let's print out the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Thank you for using my sorting program. Have a great day!\n");
    return 0;
}
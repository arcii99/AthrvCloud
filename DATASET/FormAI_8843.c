//FormAI DATASET v1.0 Category: Sorting ; Style: immersive
#include<stdio.h> // Header files used to include the standard input and output functions in our program

int main() // main function
{
    int arr[10] = {2, 8, 9, 7, 4, 6, 5, 1, 3, 0}; // Initializing an array with 10 elements
    int temp; // Temporary variable used for swapping
    int n = 10; // Size of the array

    printf("Unsorted Array: "); // Output statement to print the unsorted array

    for(int i = 0; i < n; i++) // Loop to print the unsorted array
    {
        printf("%d ", arr[i]); // Printing each element of the array
    }

    printf("\n\n");

    // Insertion Sort algorithm
    for(int i = 1; i < n; i++) // Loop to traverse the array
    {
        for(int j = i; j > 0; j--) // Loop to compare and swap adjacent elements
        {
            if(arr[j] < arr[j-1]) // If the current element is smaller than the adjacent element
            {
                temp = arr[j]; // Swapping both the elements
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    printf("Sorted Array: "); // Output statement to print the sorted array

    for(int i = 0; i < n; i++) // Loop to print the sorted array
    {
        printf("%d ", arr[i]); // Printing each element of the array
    }

    return 0; // End of program
}
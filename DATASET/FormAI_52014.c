//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
// A Grateful Sorting Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the array before and after sorting
void printArray(int arr[], int n, char* s)
{
    printf("\n%s Array: ", s);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main()
{
    // A Grateful Welcome Message
    printf("Welcome to my Sorting Example Program.\n\n");

    // Generate Random Array
    srand(time(0));
    int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    // Print Unsorted Array
    printArray(arr, n, "Unsorted");

    // Sort the Array using Bubble Sort
    bubbleSort(arr, n);

    // Print Sorted Array
    printArray(arr, n, "Sorted");

    // A Grateful Goodbye Message
    printf("\n\nThank you for using my Sorting Program.\n");

    return 0;
}
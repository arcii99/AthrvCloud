//FormAI DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>

// function to swap two integers
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// function to perform sorting using bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // last i elements are already sorted
        for (j = 0; j < n-i-1; j++)
        {
            // check if current element is greater than next element
            if (arr[j] > arr[j+1])
            {
                // if yes, swap the elements
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Welcome to the Immersive Sorting Experience!\n");
    printf("Before sorting, the array looks like:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // perform bubble sort
    bubbleSort(arr, n);

    printf("\n\nNow, after sorting, the array looks like:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nThank you for experiencing sorting with us!\n");

    return 0;
}
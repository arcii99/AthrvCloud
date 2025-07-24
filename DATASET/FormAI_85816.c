//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>

//Function to display the array
void displayArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement bubble sort algorithm
void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size-1; i++)    
        // Last i elements are already sorted
        for (j = 0; j < size-i-1; j++)  
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int arr[] = {8, 76, 11, 25, 49, 13}; //Unsorted array

    int size = sizeof(arr)/sizeof(arr[0]); //Calculate size of array

    printf("Original Array:\n");
    displayArr(arr, size); //Display the original array

    bubbleSort(arr, size); //Sort the array using bubble sort algorithm

    printf("\nSorted Array:\n");
    displayArr(arr, size); //Display the sorted array

    return 0;
}
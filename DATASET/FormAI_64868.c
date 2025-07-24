//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>

// Function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)     
  
        // Last i elements are already in place    
        for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Function to print array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
    return 0;
}
//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    
    // Print original array
    printf("Original array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    // Sort array
    bubbleSort(arr, n);
    
    // Print sorted array
    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
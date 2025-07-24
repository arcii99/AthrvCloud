//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>

// Function to swap integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 2, 9, 15, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("\n\nSorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
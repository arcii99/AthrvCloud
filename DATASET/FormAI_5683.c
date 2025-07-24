//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
#include<stdio.h>

// function to swap two integers
void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to implement selection sort
void selectionSort(int arr[], int n) 
{
    int i, j, minIndex;

    for (i = 0; i < n-1; i++) 
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
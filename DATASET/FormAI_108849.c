//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include<stdio.h>

void bubbleSort(int arr[], int n);

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\n\nSorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
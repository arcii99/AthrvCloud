//FormAI DATASET v1.0 Category: Sorting ; Style: realistic
#include<stdio.h>

void bubbleSort(int arr[], int size)
{
    int i, j, temp;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
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
    int arr[] = {9, 2, 7, 4, 5, 1, 6, 8, 3, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, size);
    printf("Array after sorting in ascending order:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
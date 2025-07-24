//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>

#define SIZE 5

void printArray(int arr[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[])
{
    int i, j, min, temp;
    for(i = 0; i < SIZE-1; i++)
    {
        min = i;
        for(j = i+1; j < SIZE; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[SIZE] = {5, 1, 9, 3, 7};

    printf("Original array:\n");
    printArray(arr);

    printf("Array after performing selection sort:\n");
    selectionSort(arr);
    printArray(arr);

    return 0;
}
//FormAI DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// function to print the array
void printArray(int arr[])
{
    printf("\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// selection sort function
void selectionSort(int arr[])
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            // visualization code start
            printf("i = %d, j = %d: \n", i, j);
            for (int k = 0; k < MAX_SIZE; k++)
            {
                if (k == i)
                {
                    printf("| %d ", arr[k]);
                }
                else if (k == j)
                {
                    printf("- %d ", arr[k]);
                }
                else
                {
                    printf("%d ", arr[k]);
                }
                
            }
            printf("|\n\n");
            // visualization code end
            
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            // visualization code start
            printf("Swapping %d and %d\n\n", arr[minIndex], arr[i]);
            // visualization code end
            
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

// main function
int main()
{
    int arr[MAX_SIZE];

    // initialize the array with random values
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // print the original array
    printf("Original array:\n");
    printArray(arr);

    // perform selection sort
    selectionSort(arr);

    // print the sorted array
    printf("Sorted array:\n");
    printArray(arr);

    return 0;
}
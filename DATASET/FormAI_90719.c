//FormAI DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main()
{
    int arr[ARRAY_SIZE];
    int i, j, temp;

    // Fill array with random numbers
    srand(time(NULL));
    for(i=0;i<ARRAY_SIZE;i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Original Array:\n");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Sort array in descending order using bubble sort algorithm
    for(i=0;i<ARRAY_SIZE-1;i++)
    {
        for(j=0;j<ARRAY_SIZE-i-1;j++)
        {
            if(arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted Array:\n");
    for(i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Display message based on the highest value in the sorted array
    if(arr[0] > 90)
    {
        printf("These are the survivors who passed the post-apocalyptic test.\n");
    }
    else if(arr[0] > 70)
    {
        printf("These are the survivors who barely made it through the post-apocalyptic test.\n");
    }
    else
    {
        printf("These did not make it through the post-apocalyptic test.\n");
    }

    return 0;
}
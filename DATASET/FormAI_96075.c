//FormAI DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Sorting Matrix\n\n");
    printf("In this dystopian world, you must sort the code by order of magnitude\n\n");
    printf("Your mission begins now...\n\n");

    // Generate random array
    srand(time(NULL));
    int arr[10];
    printf("Unsorted code: ");
    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    // Bubble sort
    int temp;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print sorted array
    printf("\n\nSorted code: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nCongratulations, you have successfully sorted the code and prevented a cyber attack!\n");
    return 0;
}
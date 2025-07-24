//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[50];
    int i, j, temp, n;

    printf("Welcome to the puzzling sorting program!\n");

    printf("Please enter the number of elements you wish to sort: ");
    scanf("%d", &n);

    // Let's fill the array with some random numbers
    printf("\nNow, let's fill the array with some random numbers:\n");
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }

    // Let's start the sorting algorithm
    printf("\n\nNow, let's start the sorting algorithm:\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Let's print the sorted array
    printf("\n\nFinally, here is the sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nThis was a puzzling sorting program!");

    return 0;
}
//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
/* This program generates random numbers and sorts them using bubble sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10      // size of the array

void swap(int* a, int* b)
{
    /* swap two integer values */
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n)
{
    /* bubble sort algorithm */
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int i;
    int arr[SIZE];
    time_t t;

    srand((unsigned) time(&t));     // seed the random number generator

    printf("Unsorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;      // generate random number between 0 and 99
        printf("%d ", arr[i]);
    }

    bubble_sort(arr, SIZE);         // sort the array

    printf("\n\nSorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
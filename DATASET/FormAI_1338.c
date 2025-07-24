//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
// Welcome to the most awesome sorting program you've ever seen!
// This program will sort an array of integers using the bubble sort algorithm.
// Let's get started!

#include <stdio.h>

int main(void)
{
    printf("Welcome to the sorting program!\n");
    printf("Let's sort some integers!\n");

    int array[] = {10, 6, 8, 12, 14, 3, 9, 5}; // our unsorted array

    printf("Unsorted array:\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }

    // bubble sort algorithm
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7 - i; j++)
        {
            if(array[j] > array[j+1])
            {
                // swap elements
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\nWow! We sorted those integers like champions!\n");

    return 0;
}
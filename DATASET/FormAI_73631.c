//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
/*
 * A Statistical Sort Example Program
 * 
 * This program sorts an array of integers using statistical sorting.
 * Statistical sorting works by analyzing the frequency distribution of the
 * values in the array, and then using that information to sort the array.
 *
 * Note: It is assumed that the array contains integers in the range 0-99.
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main(void)
{
    int array[ARRAY_SIZE];
    int counts[100] = {0};

    // Generate an array of random integers
    printf("Generating array of random integers...\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
         array[i] = rand() % 100;
    }

    // Calculate the frequency distribution of the values in the array
    printf("Calculating frequency distribution...\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        counts[array[i]]++;
    }

    // Sort the array using the frequency distribution
    printf("Sorting array using frequency distribution...\n");
    int index = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            array[index++] = i;
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
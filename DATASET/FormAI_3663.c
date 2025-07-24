//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize the random number generator

    int arr[1000];
    for (int i=0; i<1000; i++)
    {
        arr[i] = rand() % 1000 + 1; // Populate the array with random numbers between 1 and 1000
    }

    int max = 0, min = arr[0], sum = 0;

    for (int i=0; i<1000; i++)
    {
        if (arr[i] > max) // Find the maximum value in the array
        {
            max = arr[i];
        }

        if (arr[i] < min) // Find the minimum value in the array
        {
            min = arr[i];
        }

        sum += arr[i]; // Add up all the values in the array
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Sum of all values: %d\n", sum);

    int average = sum / 1000; // Calculate the average value in the array

    printf("Average value: %d\n", average);

    return 0;
}
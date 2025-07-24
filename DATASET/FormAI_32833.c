//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>

#define MAX_NUMBERS 100000

int main()
{
    int numbers[MAX_NUMBERS];

    // Populate the array with numbers from 0 to MAX_NUMBERS-1
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        numbers[i] = i;
    }

    // Shuffle the array randomly
    for (int i = MAX_NUMBERS - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);

        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Sort the array using bubble sort
    for (int i = 0; i < MAX_NUMBERS - 1; i++)
    {
        for (int j = 0; j < MAX_NUMBERS - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
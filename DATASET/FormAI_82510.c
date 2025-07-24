//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

// Configurable options
#define MAX_NUMBERS 100 // Maximum number of integers
#define MULTIPLIER 2 // Multiplier used for arithmetic operation

int main()
{
    int numbers[MAX_NUMBERS];
    int num_elements;

    // Input the integers
    printf("Enter number of integers (less than or equal to %d) to perform arithmetic operation: ", MAX_NUMBERS);
    scanf("%d", &num_elements);

    printf("Enter %d integers: ", num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // Perform arithmetic operation
    for (int i = 0; i < num_elements; i++)
    {
        numbers[i] = numbers[i] * MULTIPLIER;
    }

    // Output the result
    printf("Result after multiplying the integers by %d: ", MULTIPLIER);
    for (int i = 0; i < num_elements; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
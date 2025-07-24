//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 10

int main()
{
    int *values = (int*) malloc(sizeof(int) * MAX_VALUES);
    int num_values = 0;

    if (values == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    printf("Enter up to %d integer values (ctrl+d when finished):\n", MAX_VALUES);

    // read in values from user
    while (scanf("%d", &values[num_values]) == 1)
    {
        num_values++;

        // check if we have reached maximum number of values
        if (num_values == MAX_VALUES)
        {
            printf("Maximum number of values reached.\n");
            break;
        }
    }

    printf("You entered %d values:\n", num_values);

    // print all the values
    for (int i = 0; i < num_values; i++)
    {
        printf("%d\n", values[i]);
    }

    // free the allocated memory
    free(values);

    return 0;
}
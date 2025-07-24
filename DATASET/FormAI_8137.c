//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int current = 0;
    int prev = 0;
    int temp = 0;
    int maxLimit = 25;
    int delay = 90000;

    printf("Fibonacci Sequence Visualizer:\n\n");

    for (int i = 0; i < maxLimit; i++)
    {
        if (i == 0)
        {
            current = 1;
            printf("%d", current);
        }
        else
        {
            temp = current;
            current += prev;
            prev = temp;
            printf(", %d", current);

            for (int j = 0; j < current; j++)
            {
                printf("*");
                usleep(delay);
            }
        }

        printf("\n");
    }

    return 0;
}
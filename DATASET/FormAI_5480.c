//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

int main()
{
    int limit, i, first = 0, second = 1, next;

    printf("Enter the number of terms you want in the Fibonacci Sequence: ");
    scanf("%d", &limit);

    printf("The Fibonacci Sequence for %d terms is:\n", limit);

    for (i = 0; i < limit; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        for (int j = 0; j < next; j++)
        {
            printf("# ");
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>

void drawFibonacci(int number)
{
    int first = 0, second = 1, next, i, j;
    printf("The first %d numbers in the Fibonacci sequence are:\n\n", number);
    for (i = 0; i < number ; i++ )
    {
        if (i == 0)
            next = 1;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d\t", next);
        for (j = 0; j < next; j++)
        {
            if ((i == 0 && j == 0) || (i == 1 && j == 1))
                printf("O");
            else if (i % 2 == 0 && j % 2 == 0)
                printf("\\");
            else if (i % 2 == 0 && j % 2 != 0)
                printf("/");
            else if (i % 2 != 0 && j % 2 == 0)
                printf("|");
            else
                printf("-");
        }
        printf("\n");
    }
}

int main()
{
    int number;
    printf("Enter the number of Fibonacci sequence elements you want to see: ");
    scanf("%d", &number);
    drawFibonacci(number);
    return 0;
}
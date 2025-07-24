//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci Series: ");

    for (i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            printf("%d ", first);
            continue;
        }
        if (i == 2)
        {
            printf("%d ", second);
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms:\n");
    scanf("%d", &n);

    printf("Fibonacci Sequence:\n");
    printf("%d %d ", first, second);

    for (i = 3; i <= n; i++)
    {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    return 0;
}
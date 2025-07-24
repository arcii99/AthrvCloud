//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, nth;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++)
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

        nth = first + second;
        first = second;
        second = nth;

        printf("%d ", nth);
    }

    return 0;
}
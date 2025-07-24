//FormAI DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>

int recursiveFunction(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return recursiveFunction(n - 1) + recursiveFunction(n - 2);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The Fibonacci series: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", recursiveFunction(i));
    }

    return 0;
}
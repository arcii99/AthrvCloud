//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int pre = fibonacci(n - 1);
    int prepre = fibonacci(n - 2);

    return pre + prepre;
}

int main()
{
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d terms:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}
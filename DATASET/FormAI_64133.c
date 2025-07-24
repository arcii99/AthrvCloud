//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>

int factorial(int n);

int main()
{
    int n, fact;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error: the number must be positive!\n");
        return 1;
    }

    fact = factorial(n);
    printf("%d! = %d\n", n, fact);

    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
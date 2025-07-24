//FormAI DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int n, i = 0, c;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");

    for (c = 1; c <= n; c++)
    {
        printf("%d ", fibonacci(i));
        i++;
    }

    return 0;
}
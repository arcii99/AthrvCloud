//FormAI DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()
{
    int n;

    printf("Enter the number of terms to calculate in the Fibonacci series:\n");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", fibonacci(i));
    }

    return 0;
}
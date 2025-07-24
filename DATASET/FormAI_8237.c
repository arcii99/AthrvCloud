//FormAI DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i = 0;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("Fibonacci series terms: ");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n, result;
    printf("Enter the number you wish to calculate the fibonacci series of: ");
    scanf("%d", &n);

    result = fibonacci(n);

    printf("The fibonacci series of %d is: %d\n", n, result);
    return 0;
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
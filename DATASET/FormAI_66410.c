//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;

    printf("Enter the number of terms to print in the Fibonacci series: ");
    scanf("%d", &n);

    printf("The fibonacci series is: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
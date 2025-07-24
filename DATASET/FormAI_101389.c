//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n)
{
    if (n <= 1) // Base case
        return n;
    else // Recursive case
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

// Fibonacci Series using Recursion
int fibonacci(int n)
{
    // Base Case
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    // Recursive Case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    return 0;
}
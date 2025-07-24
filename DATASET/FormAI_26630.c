//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
/* Dynamic C program to find the Fibonacci sequence using recursion */

#include <stdio.h>

int fib(int n) // Recursive function to find the fibonacci sequence
{
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int num, i;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &num);
    printf("The Fibonacci sequence is:\n");

    for (i = 0; i < num; i++)
    {
        printf("%d ", fib(i));
    }

    return 0;
}
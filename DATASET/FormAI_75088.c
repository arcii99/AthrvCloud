//FormAI DATASET v1.0 Category: Recursive ; Style: ephemeral
// Let's create a program that calculates the nth Fibonacci number using recursive function calls

#include <stdio.h>

int fib(n)
{
    if (n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int result = fib(n);
    printf("The %dth Fibonacci number is %d", n, result);
    
    return 0;
}
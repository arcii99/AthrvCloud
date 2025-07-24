//FormAI DATASET v1.0 Category: Scientific ; Style: innovative
#include <stdio.h>

// a function to calculate the fibonacci sequence of n numbers
int fibonacci(int n)
{
    // the first two numbers in the sequence are 0 and 1
    int fib1 = 0, fib2 = 1;
    
    // loop through the sequence and calculate each number
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fib1);
        int nextFib = fib1 + fib2;
        fib1 = fib2;
        fib2 = nextFib;
    }
    
    return 0;
}

int main()
{
    int n;
    printf("How many numbers in the fibonacci sequence would you like to calculate?\n");
    scanf("%d", &n);
    
    fibonacci(n);
    
    return 0;
}
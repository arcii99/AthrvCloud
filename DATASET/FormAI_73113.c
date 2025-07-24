//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int n);

int main()
{
    int num;    
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("The %dth Fibonacci number is %d", num, fibonacci(num));

    return 0;
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
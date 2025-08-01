//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int factorial(int n);

int main()
{
    int num = 5;
    int result = factorial(num);
    
    printf("Factorial of %d is %d\n", num, result);
    
    return 0;
}

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}
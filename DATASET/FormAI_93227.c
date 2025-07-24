//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;   // base case
    else
        return n * factorial(n-1);  // recursive call
}

int main()
{
    unsigned int n = 5;
    printf("Factorial of %u is %u", n, factorial(n));
    return 0;
}
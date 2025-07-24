//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    int fact = factorial(num);
    printf("%d! = %d\n", num, fact);
    return 0;
}

int factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
        return 1;
    // Recursive case
    else
        return n * factorial(n-1);
}
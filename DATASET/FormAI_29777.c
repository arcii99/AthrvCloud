//FormAI DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>

int calculateSum(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + calculateSum(n-1);
    }
}

int main()
{
    int n, sum;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    sum = calculateSum(n);

    printf("Sum of first %d natural numbers is %d\n", n, sum);

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>

int factorial(int num)
{
    if(num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    int num, fact;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 0)
    {
        printf("Factorial of negative number is not possible\n");
    }
    else
    {
        fact = factorial(num);
        printf("Factorial of %d is %d\n", num, fact);
    }
    return 0;
}
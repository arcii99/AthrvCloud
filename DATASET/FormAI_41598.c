//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include <stdio.h>

//Recursive function to calculate the factorial of a number
int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int num, fact;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    if(num < 0)
        printf("Factorial of negative numbers is not defined!");
    else
    {
        fact = factorial(num);
        printf("Factorial of %d is %d.", num, fact);
    }

    return 0;
}
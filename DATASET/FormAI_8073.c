//FormAI DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>

/* Function to calculate factorial of a given number */
int factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

/* Function to calculate nCr */
int nCr(int n, int r)
{
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n-r);
    int nCr = numerator / denominator;
    return nCr;
}

/* Main function */
int main()
{
    /* Get input from user */
    int n,r;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of r: ");
    scanf("%d",&r);

    /* Check for invalid input */
    if(r>n || n<0 || r<0)
    {
        printf("Invalid input\n");
    }
    else
    {
        /* Calculate nCr */
        int result = nCr(n,r);
        printf("nCr = %d\n",result);
    }
    return 0;
}
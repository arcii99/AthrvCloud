//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include<stdio.h>
#include<stdlib.h>

// function to calculate sum of n numbers
int sum(int n)
{
    int i, s=0;
    for(i=1; i<=n; i++)
    {
        s+=i;
    }
    return s;
}

// function to calculate factorial of a number
int factorial(int n)
{
    int f=1, i;
    for(i=1; i<=n; i++)
    {
        f*=i;
    }
    return f;
}

// main function
int main()
{
    int n, sum_res, fact_res;
    
    // take user input
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // calculate sum and factorial
    sum_res = sum(n);
    fact_res = factorial(n);
    
    // print the results
    printf("Sum of first %d numbers = %d\n", n, sum_res);
    printf("Factorial of %d = %d\n", n, fact_res);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

// Recursive function to calculate the sum of n natural numbers
int sum(int n)
{
    if(n == 1)
        return 1;
    else
        return n + sum(n-1);
}

// Multivariable function to calculate the factorial and sum of even numbers
void factEvenSum(int n, int *fact, int *evenSum)
{
    if(n == 0)
    {
        *fact = 1;
        *evenSum = 0;
    }
    else
    {
        factEvenSum(n-1, fact, evenSum);
        *fact *= n;
        if(n%2 == 0)
            *evenSum += n;
    }
}

// Main function to test the recursive and multivariable functions
int main()
{
    int num = 5;
    printf("The sum of first %d natural numbers is %d\n", num, sum(num));
    
    int fact = 0, evenSum = 0;
    factEvenSum(num, &fact, &evenSum);
    printf("The factorial of %d is %d\n", num, fact);
    printf("The sum of even numbers up to %d is %d\n", num, evenSum);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

int complex_factorial(int n);

int main()
{
    int num;
    printf("Enter a number to calculate the factorial: ");
    scanf("%d",&num);
    if(num < 0)
    {
        printf("Factorial for negative number does not exist!");
    }
    else
    {
        printf("Factorial of %d is: %d", num, complex_factorial(num));
    }
    
    return 0;
}

int complex_factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n < 0)
    {
        return n * complex_factorial(n+1);
    }
    else if(n%2 == 0)
    {
        return complex_factorial(n/2);
    }
    else
    {
        return n * complex_factorial(n-1);
    }
}
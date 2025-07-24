//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

// Post-apocalyptic style program to calculate factorial using recursive function

int factorial(int n)
{
    if(n<0) // condition to handle negative input
    {
        printf("Invalid input! Please enter a non-negative integer");
        exit(0);
    }
    else if(n==0 || n==1) // base case
    {
        return 1;
    }
    else 
    {
        printf("%d * ",n); // prints the value of n in the calculation process
        return n*factorial(n-1); // recursive call to multiply n with factorial of n-1
    }
}

int main()
{
    int num,fact;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d",&num);

    fact = factorial(num);

    printf("\b\b= %d",fact); // removes the unwanted '*' and prints the result

    return 0;
}

// End of program
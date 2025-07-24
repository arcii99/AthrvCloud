//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

/* This program calculates the factorial of a number using recursion */

long int factorial(int n);

int main()
{
    int n;
    long int fact;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }
    
    fact = factorial(n);
    
    printf("%d! = %ld\n", n, fact);
    
    return 0;
}

long int factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}
//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

// Function prototype
long fibonacci(int);

int main()
{
    int n;
    long result;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    
    if(n < 0)
    {
        printf("Invalid input!\n");
        return 0;
    }
    
    result = fibonacci(n);
    
    printf("The %dth fibonacci number is %ld", n, result);
    
    return 0;
}

// Recursive function to calculate fibonacci sequence
long fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
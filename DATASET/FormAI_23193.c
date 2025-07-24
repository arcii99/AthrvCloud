//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

// Recursive Fibonacci function
int fibonacci(int n)
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

// Main function
int main()
{
    int n;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
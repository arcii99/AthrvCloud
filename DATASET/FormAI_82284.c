//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int main()
{
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the input is a positive integer
    if(num < 0)
    {
        printf("Error: Invalid input!");
        return 0;
    }

    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);

    // Check if the result is too large to be stored in an int
    if(fact < 0 || fact > 2147483647)
    {
        printf("Warning: Result too large to be stored in an int!\n");
    }

    return 0;
}
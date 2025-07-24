//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

// A simple recursive function to calculate factorial
unsigned int factorial(unsigned int n)
{
    if (n == 1) // Base case
        return 1;
    else
        return n * factorial(n-1); // Recursive case
}

int main()
{
    printf("Welcome to Factorial Calculator!\n\n");
    
    int input;
    printf("Please enter a positive integer: ");
    scanf("%d", &input);
    
    // Validation check
    if (input < 0)
    {
        printf("Invalid input!\n");
        return 0;
    }

    unsigned int result = factorial(input);
    printf("The factorial of %d is %d\n", input, result);
    
    printf("\nThank you for using Factorial Calculator!\n");
    return 0;
}
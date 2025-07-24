//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

// Function to calculate the factorial of a given number using recursion
int factorial(int n)
{
    // Base case: if n is 0 or 1, return 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive case: call the factorial function with n-1 and multiply it with n
    else 
    {
        return n * factorial(n-1);
    } 
}

int main()
{
    int n;

    printf("Welcome to the factorial calculator\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &n);

    // Check if the user has entered a negative number
    if (n < 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
    }
    else
    {
        // Call the factorial function with the input number
        int result = factorial(n);

        // Print the result
        printf("The factorial of %d is %d\n", n, result);
    }

    return 0;
}
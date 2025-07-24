//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>

// Function to calculate factorial of a given number
unsigned long long int factorial(unsigned int n)
{
    // Base case
    if (n == 0)
        return 1;

    // Recursive case
    return n * factorial(n - 1);
}

// Main function
int main()
{
    // Declare variables
    unsigned int n, r;
    unsigned long long int n_factorial, r_factorial, n_minus_r_factorial, combination;

    // Input the values of n and r
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);

    // Calculate factorials
    n_factorial = factorial(n);
    r_factorial = factorial(r);
    n_minus_r_factorial = factorial(n - r);

    // Calculate combination
    combination = n_factorial / (r_factorial * n_minus_r_factorial);

    // Output the result
    printf("The combination of %d and %d is: %llu\n", n, r, combination);

    return 0;
}
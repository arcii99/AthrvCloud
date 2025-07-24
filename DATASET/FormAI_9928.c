//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
/*
 * Program: Fibonacci series using recursion
 * Language: C
 * Developer: [Your Name]
*/

#include <stdio.h>

// Function to calculate the nth term of the Fibonacci series
int fibonacci(int n)
{
    // Base case for recursion
    if(n <= 1)
        return n;

    // Recursive call to calculate the nth term
    return fibonacci(n-1) + fibonacci(n-2);
}

// Main function to drive the program
int main()
{
    int n, i;

    // Get the limit for the series from the user
    printf("Enter the limit for the series: ");
    scanf("%d", &n);

    // Print the fibonacci series
    printf("Fibonacci series up to %d terms:\n", n);
    for(i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    return 0;
}
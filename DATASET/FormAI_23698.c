//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>

// Function to calculate n!
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n-1); // Recursive call
}

// Function to print the Fibonacci series until n
void fibonacci(int n)
{
    static int a = 0, b = 1; // Static variables to hold the previous two numbers in the series
    if (n == 0)
        return;
    int c = a + b;
    a = b;
    b = c;
    printf("%d ", c);
    fibonacci(n-1); // Recursive call
}

// Main function
int main()
{
    // Test factorial function
    int num = 5;
    int result = factorial(num);
    printf("%d! = %d\n", num, result);

    // Test fibonacci function
    printf("Fibonacci series until 10: ");
    fibonacci(10);
    printf("\n");

    return 0;
}
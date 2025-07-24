//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>

// Recursive function to calculate the Fibonacci series
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    // Declare variables to hold user input and the result of the recursion
    int n, result;

    // Prompt the user to enter the nth number of the Fibonacci series
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    // Call the recursive function to calculate the result
    result = fib(n);

    // Print the result to the console
    printf("The %dth number in the Fibonacci series is %d.", n, result);

    // Return 0 to indicate successful execution of the program
    return 0;
}

/*
Example Output:

Enter the number of terms in Fibonacci series: 10
The 10th number in the Fibonacci series is 55.
*/
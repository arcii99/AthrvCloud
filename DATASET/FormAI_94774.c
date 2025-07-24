//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>

// Function to generate and visualize Fibonacci sequence up to N using recursive method
void fib_sequence(int n, int l_n, int sl_n)
{
    if(n>0)
    {
        int t_n = l_n+sl_n; // Calculate next Fibonacci number
        printf("%d ", t_n); // Print the generated number

        // Generate the next number in the sequence
        fib_sequence(n-1, t_n, l_n);
    }
}

int main()
{
    int n;

    // Get input from the user
    printf("Enter the number of terms to be generated: ");
    scanf("%d", &n);

    if(n<=0)
    {
        printf("Invalid input! Number of terms must be greater than zero.");
        return 0;
    }

    // Print the first two terms of the sequence
    printf("Fibonacci sequence up to %d terms: \n0 1 ", n);

    // Generate and print the remaining terms of the sequence
    fib_sequence(n-2, 1, 0);

    return 0;
}
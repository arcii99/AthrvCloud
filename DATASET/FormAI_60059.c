//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence
void fibonacci(int n)
{
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Printing the Fibonacci sequence in a visual manner
    printf("\n=============================\n");
    printf("| Index | Fibonacci Number |\n");
    printf("=============================\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %5d | %16d |\n", i, fib[i]);
    }

    printf("=============================\n");
}

int main()
{
    int n;

    // Reading the number of terms from the user
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Calling the Fibonacci function to calculate and print the sequence
    fibonacci(n);

    return 0;
}
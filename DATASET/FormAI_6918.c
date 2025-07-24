//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the n-th Fibonacci number recursively
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int numTerms, i;

    printf("Enter the number of terms to display: ");
    scanf("%d", &numTerms);

    printf("Fibonacci Sequence for first %d terms:\n", numTerms);

    // Loop to print the Fibonacci sequence for the specified number of terms
    for (i = 0; i < numTerms; i++) {

        // Print the current Fibonacci number
        printf("%d ", fibonacci(i));
        
        // Pauses the program for a short period to create a visual effect
        system("sleep 0.5");
        
        // Prints "*"'s to create a visual effect of the Fibonacci sequence
        for (int j = 0; j < fibonacci(i); j++) {
            printf("*");
        }

        printf("\n");   // New line for the next Fibonacci number
    }

    return 0;
}
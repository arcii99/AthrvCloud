//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to return the nth Fibonacci number using recursion
int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int num_terms, i, j;

    // Read number of terms from user
    printf("Enter the number of terms to generate in the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    // Iterate through each term and print it
    for(i = 0; i < num_terms; i++)
    {
        // Print the ith term with appropriate spacing
        printf("%d", fibonacci(i));
        for(j = i+1; j < num_terms; j++)
        {
            printf("   ");
        }
    printf("\n");
    }
    return 0;
}
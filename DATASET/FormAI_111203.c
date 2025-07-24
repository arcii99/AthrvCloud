//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to compute the Nth Fibonacci number
int fibonacci(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    
    // Get input from the user
    printf("Please enter the number of terms to generate in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    // Create the array to store the numbers in the sequence
    int* sequence = (int*) malloc(n * sizeof(int));
    
    // Generate the sequence
    for (int i = 0; i < n; i++)
    {
        sequence[i] = fibonacci(i);
    }
    
    // Print the sequence
    printf("The first %d terms of the Fibonacci sequence are:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sequence[i]);
    }
    
    // Free the memory used to store the sequence
    free(sequence);
    
    return 0;
}
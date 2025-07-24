//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

// Function prototype
void generateFibonacci(int limit);

int main() {
    int limit;
    printf("Enter the number of terms to generate in the Fibonacci sequence: ");
    scanf("%d", &limit);
    
    // Call generateFibonacci function to generate and print the sequence
    generateFibonacci(limit);

    return 0;
}

// Function to generate the Fibonacci sequence up to a given limit
void generateFibonacci(int limit)
{
    // Initialize variables to store the first two terms of the sequence
    int n1 = 0, n2 = 1;
    
    // Print the first two terms of the sequence
    printf("%d %d ", n1, n2);
    
    // Loop to generate and print the rest of the terms in the sequence
    for(int i=0; i<limit-2; i++)
    {
        // Calculate the next term by adding the previous two terms
        int n3 = n1 + n2;
        
        // Print the current term
        printf("%d ", n3);
        
        // Update the values of n1 and n2 to prepare for the next iteration
        n1 = n2;
        n2 = n3;
    }
}
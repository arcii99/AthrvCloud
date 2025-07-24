//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

// Function to calculate and print Fibonacci sequence up to n terms
void fibonacciSequence(int n)
{
    int prev = 0, curr = 1, next, i;
    
    // Print first two terms
    printf("%d %d ", prev, curr);
    
    // Print rest of the terms
    for(i = 3; i <= n; i++)
    {
        next = prev + curr;
        printf("%d ", next);
        prev = curr;
        curr = next;
    }
}

int main()
{
    int n;
    
    printf("Enter number of terms to display in Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence up to %d terms:\n", n);
    fibonacciSequence(n);
    
    return 0;
}
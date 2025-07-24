//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

// Function to calculate Fibonacci sequence up to n
void fibonacci(int n)
{
    int a = 0, b = 1, c, i;
    
    // Printing first two terms of the sequence
    printf("%d %d ", a, b);
    
    // Calculating and printing rest of the terms of the sequence
    for(i=3; i<=n; i++)
    {
        c = a + b;
        printf("%d ", c);
        
        // Updating variables for next iteration
        a = b;
        b = c;
    }
}

int main()
{
    int n;
    
    printf("Enter the number of terms to be displayed: ");
    scanf("%d", &n);
    
    // Calling the fibonacci function
    fibonacci(n);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence up to n terms
void fibonacci(int n)
{
    int i, first = 0, second = 1, next;
    
    printf("Fibonacci sequence up to %d terms:\n", n);
    
    // Loop through n terms and calculate the next number in the sequence
    for(i=0; i<n; i++)
    {
        if(i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
        
        // Output a visual representation of the current number as a bar chart
        printf(": ");
        for(int j=0; j<next; j++)
        {
            printf("=");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    
    // Get user input for the number of terms to calculate
    printf("Enter the number of terms to calculate: ");
    scanf("%d", &n);
    
    // Call the fibonacci function to calculate and display the sequence
    fibonacci(n);
    
    return 0;
}
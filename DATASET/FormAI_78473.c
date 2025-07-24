//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>

// function to get the nth fibonacci number
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    printf("Enter the number of terms you want in Fibonacci sequence: ");
    scanf("%d", &n);
    
    // Print the Fibonacci Sequence of n terms
    int prev = 0, current = 1, next;
    printf("\nFibonacci Sequence:\n");
    printf("%d, %d, ", prev, current);     // print first two terms
    for (int i = 3; i <= n; i++)
    {
        next = prev + current;
        printf("%d, ", next);
        prev = current;
        current = next;
    }

    // Extra feature: Print n-th Fibonacci number
    printf("\n\nThe %d-th Fibonacci number is: %d\n", n, fibonacci(n));

    return 0;   // Exit code
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>

int fibonacci(int n);
void display(int n);

int main()
{
    int n;

    printf("Enter number of terms to display: ");
    scanf("%d", &n);

    printf("\nFibonacci sequence: \n");
    display(n);

    return 0;
}

// Function to calculate nth fibonacci number
int fibonacci(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to display fibonacci sequence
void display(int n)
{
    int i;

    // loop through n terms and call fibonacci function for each term
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
}
//FormAI DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>

// Helper function
int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to print the fibonacci sequence
void printFibonacci(int n)
{
    if (n < 1) {
        printf("Invalid number! \n");
        return;
    }

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Main function
int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}
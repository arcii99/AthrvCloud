//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

int main() {
    int n, i, fib[50];

    // Taking input from user
    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);

    // Initializing first two terms
    fib[0] = 0;
    fib[1] = 1;

    // Generating the Fibonacci sequence
    for(i=2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Printing the Fibonacci sequence
    printf("Fibonacci Series:\n");
    for(i=0; i<n; i++) {
        printf("%d ", fib[i]);
    }

    return 0;
}
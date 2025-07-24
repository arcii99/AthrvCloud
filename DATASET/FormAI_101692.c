//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>

// function to generate fibonacci sequence and return an array
int* generateFibonacci(int limit) {
    static int fib[50];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}


int main(void) {
    int limit;

    // get user input for fibonacci limit
    printf("Enter the limit for fibonacci sequence: ");
    scanf("%d", &limit);

    // call function to generate fibonacci sequence
    int* fibonacci = generateFibonacci(limit);

    // Displaying the Fibonacci sequence with bar chart visualization
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < limit; i++) {
        printf("%d: ", fibonacci[i]);

        for (int j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
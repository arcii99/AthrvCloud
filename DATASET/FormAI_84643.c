//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>

void fibonacci_sequence_visualizer(int n) {
    // Initialize variables
    int i, t1 = 0, t2 = 1, next_term;

    // Print Fibonacci sequence
    printf("The first %d terms of the Fibonacci sequence are:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d, ", t1);
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }

    // Visualize Fibonacci sequence
    printf("\n\nFibonacci sequence visualization:\n");
    for (i = 1; i <= n; i++) {
        next_term = t1 + t2;
        printf("%d: ", t1);
        int j;
        for (j = 0; j < t1; j++) {
            printf("*");
        }
        printf("\n");
        t1 = t2;
        t2 = next_term;
    }
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 1) {
        printf("Error: invalid input.\n");
        return -1;
    }

    // Call Fibonacci sequence visualizer function
    fibonacci_sequence_visualizer(n);

    return 0;
}
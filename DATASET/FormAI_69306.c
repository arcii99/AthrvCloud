//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

int fibonacci(int n);

int main() {
    int num_terms, i;
    printf("Enter the number of terms you would like to visualize for the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    // formatting for visually appealing output
    printf("\nFibonacci sequence with %d terms:\n", num_terms);
    printf(" 1  ");

    for (i = 2; i <= num_terms; i++) {
        if (i % 10 == 1) {
            printf("\n");
        }
        printf("%d ", fibonacci(i));
    }
    return 0;
}

// function to get the nth term in the Fibonacci sequence
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
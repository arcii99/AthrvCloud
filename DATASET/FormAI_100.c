//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Enter the number of terms you want to generate in the Fibonacci Sequence: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // starting with index 2, generates the remaining terms in the sequence
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nFibonacci Sequence for %d terms is: ", n);

    // prints the sequence
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    // visualizes the sequence using stars, with each star representing one term in the sequence
    printf("\n\nVisualizing the Fibonacci Sequence:\n");

    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < fib[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

void printVisualization(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int max_num_digits = snprintf(NULL, 0, "%d", fib[n-1]);

    for (int i = 0; i < n; i++) {
        int num_digits = snprintf(NULL, 0, "%d", fib[i]);

        int num_spaces = max_num_digits - num_digits;
        if (num_spaces < 0) num_spaces = 0;

        char spaces[num_spaces+1];
        memset(spaces, ' ', sizeof(spaces));
        spaces[num_spaces] = '\0';

        printf("%s%d\n", spaces, fib[i]);
    }
}

int main() {
    printf("Enter the number of terms in the Fibonacci sequence: ");
    int n;
    scanf("%d", &n);

    printf("\nFibonacci Sequence:\n");
    printFibonacci(n);

    printf("\nFibonacci Sequence Visualization:\n");
    printVisualization(n);

    return 0;
}
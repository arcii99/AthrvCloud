//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>

// function to calculate fibonacci sequence
int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms to generate of Fibonacci sequence: ");
    scanf("%d", &n);

    // print the fibonacci sequence
    for (int i = 0; i < n; i++) {
        int val = fib(i);
        printf("%d: %d | ", i + 1, val);

        // visualizer
        for (int j = 0; j < val; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
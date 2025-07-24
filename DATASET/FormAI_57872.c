//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

#define MAX_TERM 50

int main() {
    int fib[MAX_TERM] = {0, 1};
    int i, j;

    printf("Welcome to the Paranoid Fibonacci Sequence Visualizer!\n\n");

    // Calculate Fibonacci sequence
    for (i = 2; i < MAX_TERM; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the sequence
    for (i = 0; i < MAX_TERM; i++) {
        // Detect potential buffer overflow
        if (i > 0 && i % 10 == 0) {
            printf("\n");
        }

        printf("%d ", fib[i]);

        // Detect potential integer overflow
        for (j = 1; j <= i/2; j++) {
            if (fib[j] > fib[i-j]) {
                printf("\n\nWARNING: Integer overflow detected.");
                return 1;
            }
        }
    }

    printf("\n\nCongratulations, no signs of tampering found.\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;

    printf("Enter a number to generate the Fibonacci sequence: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("The first %d elements of the Fibonacci sequence are:\n", n);

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
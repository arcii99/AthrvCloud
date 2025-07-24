//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

// Function to calculate the nth fibonacci number
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// Function to display fibonacci sequence up to a given limit
void fib_visualizer(int limit) {
    printf("Fibonacci sequence up to %d:\n", limit);
    for (int i=0; i<=limit; i++) {
        for (int j=0; j<=i; j++) {
            printf("%d ", fib(j));
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the limit for the fibonacci visualizer: ");
    scanf("%d", &n);
    fib_visualizer(n);
    return 0;
}
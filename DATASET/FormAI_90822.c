//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms to display in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
        for (int j = fibonacci(i); j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursive(int n) {
    if (n < 0) {
        printf("Error: invalid input\n");
        exit(1);
    }
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Fibonacci sequence up to %dth term using recursive function:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
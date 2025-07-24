//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Fibonacci series of %d numbers: ", n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
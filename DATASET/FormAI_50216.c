//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    int fib[limit + 2]; // +2 to handle cases where limit = 0 or 1
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci series up to %d:\n", limit);
    for (int i = 0; i <= limit; i++) {
        printf("%d ", fib[i]);
    }

    return 0;
}
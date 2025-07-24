//FormAI DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        // Recursive step
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    printf("The %dth term in the Fibonacci sequence is %d", n, fibonacci(n));
    return 0;
}
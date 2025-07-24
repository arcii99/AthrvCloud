//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) { // Base case
        return n;
    } else { // Recursive case
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print the Fibonacci series up to the nth term
    printf("Fibonacci series up to %d:\n", n);
    for (int i=0; i<n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
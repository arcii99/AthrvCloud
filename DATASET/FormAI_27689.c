//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, choice;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Choose an operation:\n");
    printf("1. Calculate factorial\n");
    printf("2. Generate Fibonacci sequence\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("%d! = %d\n", n, factorial(n));
    } else if (choice == 2) {
        printf("Fibonacci sequence of length %d: ", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
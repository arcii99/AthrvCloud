//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

/* This is a recursive function that finds the nth Fibonacci number. */
int fibonacci(int n) {
    if (n == 0 || n == 1) { // Base cases
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2); // Recursive step
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) { // Error case
        printf("Invalid input\n");
        return 1;
    }

    printf("The %dth Fibonacci number is: %d\n", num, fibonacci(num));

    return 0;
}
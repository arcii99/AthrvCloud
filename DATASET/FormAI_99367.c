//FormAI DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>

// A function that prints the n-th number in the Fibonacci sequence recursively
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Enter a positive integer to find its Fibonacci number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("ERROR: please enter a positive integer\n");
        return 1;
    }
    else {
        int result = fibonacci(n);
        printf("The %dth number in the Fibonacci sequence is %d\n", n, result);
        return 0;
    }
}
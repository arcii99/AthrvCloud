//FormAI DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

// Recursive function to return the nth number in the fibonacci series
int fibonacci(int n) {

    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The %dth number in the Fibonacci series is %d", n, fibonacci(n));

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
// Ye Olde Fibonacci Sequence
#include <stdio.h>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) { // Base case for n = 0
        return 0;
    } else if (n == 1) { // Base case for n = 1
        return 1;
    } else { // Recursive call for n > 1
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter the term of the fibonacci sequence that ye desire: ");
    scanf("%d", &n);
    printf("The %dth term of the fibonacci sequence is: %d", n, fibonacci(n));
    return 0;
}
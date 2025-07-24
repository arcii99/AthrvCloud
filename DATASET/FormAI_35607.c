//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>

int Fibonacci(int n) {
    if (n < 0) {
        printf("Error: Invalid input\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Factorial(int n) {
    if (n < 0) {
        printf("Error: Invalid input\n");
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);
}
 
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));
    printf("Factorial(%d) = %d\n", n, Factorial(n));
    return 0;
}
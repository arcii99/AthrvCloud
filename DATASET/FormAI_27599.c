//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    return 0;
}
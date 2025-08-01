//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci series with %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
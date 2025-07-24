//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    } 
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms you want to see in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("\nFibonacci Series:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n\n");
    return 0;
}
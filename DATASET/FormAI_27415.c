//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, i, j;
    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j <= i; ++j) {
            printf("%d ", fibonacci(j));
        }
        printf("\n");
    }
    return 0;
}
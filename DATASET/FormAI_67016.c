//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms you want in the sequence (Minimum 2 terms): ");
    scanf("%d", &n);
    while (n < 2) {
        printf("Please enter a valid number of terms (Minimum 2 terms): ");
        scanf("%d", &n);
    }
    printf("\nFibonacci Sequence:\n\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
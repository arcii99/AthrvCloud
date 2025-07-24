//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    printf("Enter the number of terms you want to see in the Fibonacci sequence: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n\n");

    printf("Here is a visual representation of the Fibonacci sequence:\n\n");

    for (int i = 1; i <= n; i++) {
        int fib = fibonacci(i);
        printf("%d: ", fib);
        for (int j = 0; j < fib; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}
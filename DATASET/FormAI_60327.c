//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for(i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("The Fibonacci sequence for the first %d terms is:\n", n);

    for(i = 0; i < n; i++) {
        int j;
        for(j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
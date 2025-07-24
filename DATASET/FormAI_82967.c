//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void print_fib_sequence(int n) {
    printf("The first %d numbers in the Fibonacci sequence are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int num_terms;
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num_terms);

    print_fib_sequence(num_terms);

    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>

void fibonacci_visualizer(int n) {
    int prev = 0, curr = 1, next;

    for(int i = 0; i < n; ++i) {
        printf("%d", prev);

        for(int j = 0; j < prev; ++j)
            printf("*");

        printf("\n");

        next = prev + curr;
        prev = curr;
        curr = next;
    }
}

int main() {
    int n;

    printf("Enter the number of terms to display: ");
    scanf("%d", &n);

    printf("\nFibonacci Sequence with Asterisk Visualizer\n");
    printf("------------------------------------------\n");

    fibonacci_visualizer(n);

    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int n = 0;
    int prev = 0;
    int current = 1;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    printf("\nGenerating Fibonacci sequence...\n\n");

    for (int i = 1; i <= n; i++) {
        printf("%d\n", current);
        int next = prev + current;
        prev = current;
        current = next;
    }

    printf("\nFibonacci sequence generated successfully!\n");

    return 0;
}
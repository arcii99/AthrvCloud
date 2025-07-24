//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("\nFibonacci sequence visualization for n = %d:\n\n", n);
    if (n >= 1)
        printf("%d", a);
    if (n >= 2)
        printf(" %d", b);
    for (i = 2; i < n; i++) {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n\n");
}

int main() {
    int n;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");
    printf("Please enter a positive integer n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("\nInvalid input! Please enter a positive integer.\n");
        exit(0);
    }
    print_fibonacci(n);
    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}
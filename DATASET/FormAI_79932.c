//FormAI DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main() {
    int n;
    printf("Please enter a non-negative integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        exit(1);
    }
    int result = factorial(n);
    printf("The factorial of %d is %d.\n", n, result);
    return 0;
}
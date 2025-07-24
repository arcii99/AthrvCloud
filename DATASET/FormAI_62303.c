//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        printf("Cannot calculate factorial of negative numbers.\n");
        return -1;
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int n;
    printf("Enter a positive integer to calculate its factorial: ");
    scanf("%d", &n);
    int result = factorial(n);
    if (result != -1) {
        printf("%d! = %d\n", n, result);
    }
    return 0;
}
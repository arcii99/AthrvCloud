//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>

// Function to compute the factorial of a number
long int factorial(int n) {
    long int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number to compute its factorial: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }
    long int f = factorial(n);
    printf("Factorial of %d is %ld\n", n, f);
    return 0;
}
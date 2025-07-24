//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>

int factorial(int n);

int main() {
    int n, result;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        result = factorial(n);
        printf("Factorial of %d is %d\n", n, result);
    }

    return 0;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
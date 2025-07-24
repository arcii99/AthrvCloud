//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

// function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a number to calculate the factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Factorial of negative numbers is undefined.\n");
    } else {
        int result = factorial(n);
        printf("The factorial of %d is %d.\n", n, result);
    }

    return 0;
}
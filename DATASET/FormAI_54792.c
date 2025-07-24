//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Sorry, the factorial of a negative number does not exist.");
    } else {
        int result = factorial(n);
        printf("The factorial of %d is %d", n, result);
    }
    return 0;
}
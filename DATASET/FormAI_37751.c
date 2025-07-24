//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>

// This is a simple program that calculates the factorial of an integer using a loop

int factorial(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int num, result;
    printf("Enter an integer: ");
    scanf("%d", &num);
    result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}
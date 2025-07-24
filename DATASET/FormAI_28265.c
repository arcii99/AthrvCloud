//FormAI DATASET v1.0 Category: Scientific ; Style: active
#include <stdio.h>

// This program calculates the factorial of a given number using recursion

int factorial(int num) {
    // base case
    if (num == 0 || num == 1) {
        return 1;
    }
    // recursive case
    else {
        return num * factorial(num - 1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    }
    else {
        printf("The factorial of %d is %d.\n", n, factorial(n));
    }
    return 0;
}
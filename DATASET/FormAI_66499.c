//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

// Recursive function to calculate the factorial of a given number
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: calculate factorial of n-1 and multiply by n
    else {
        int fact_n_minus_1 = factorial(n - 1);
        int result = n * fact_n_minus_1;
        printf("Calculating factorial of %d: %d * %d = %d\n", n, n, fact_n_minus_1, result);
        return result;
    }
}

int main() {
    int n;
    printf("Welcome to the Factorial Calculator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Sorry, I cannot calculate the factorial of a negative number.\n");
    }
    else {
        int result = factorial(n);
        printf("The factorial of %d is: %d\n", n, result);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

// Function declaration
int factorial(int n);

int main() {
    // Integer input
    int num;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Negative number error checking
    while(num < 0) {
        printf("Error: Enter a non-negative integer: ");
        scanf("%d", &num);
    }

    // Calculation and output
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case
    if(n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n-1);
    }
}
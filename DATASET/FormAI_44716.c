//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) { // Base case: factorial of 0 is 1
        return 1;
    } else { // Recursive case: multiply n by the factorial of (n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int n, fact;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n < 0) {
        printf("Error: invalid input! Please enter a positive integer.\n");
        return 1;
    }

    fact = factorial(n);

    printf("%d! = %d\n", n, fact);

    return 0;
}
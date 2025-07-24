//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n < 0) {
        printf("Invalid input: factorial undefined for negative integers.\n");
        return -1;
    }
    else if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;

    // Prompt user to enter a number
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check if input is valid
    while (n < 0) {
        printf("Invalid input: please enter a non-negative integer.\n");
        printf("Enter a non-negative integer: ");
        scanf("%d", &n);
    }

    // Calculate factorial using recursion
    int result = factorial(n);

    // Print result
    printf("%d! = %d\n", n, result);

    return 0;
}
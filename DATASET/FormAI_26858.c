//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Welcome to the Recursive Factorial Calculator!\n");

    // Take input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        // Call the recursive function to calculate the factorial
        int result = factorial(num);
        printf("The factorial of %d is %d.\n", num, result);
    }

    printf("Thank you for using the Recursive Factorial Calculator.\n");

    return 0;
}
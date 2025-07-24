//FormAI DATASET v1.0 Category: Scientific ; Style: synchronous
#include <stdio.h>

// Function to calculate factorial of a number recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    // Get user input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate and print factorial
    int result = factorial(num);
    printf("Factorial of %d is %d", num, result);

    // Check if number is prime
    int is_prime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }

    // Print whether number is prime or not
    if (is_prime) {
        printf("%d is a prime number", num);
    } else {
        printf("%d is not a prime number", num);
    }

    return 0;
}
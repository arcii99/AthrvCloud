//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Main function
int main() {
    int number, result;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Factorial of negative number is not defined!\n");
    } else {
        result = factorial(number);
        printf("Factorial of %d is: %d\n", number, result);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include<stdio.h>

int main() {
    int num1, num2;

    // Take input from user
    printf("Hello! Let's do some arithmetic!\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Add the numbers together
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    // Subtract the second number from the first number
    int diff = num1 - num2;
    printf("The difference between %d and %d is %d\n", num1, num2, diff);

    // Multiply the numbers together
    int product = num1 * num2;
    printf("The product of %d and %d is %d\n", num1, num2, product);

    // Divide the first number by the second number
    // Make sure the second number isn't 0!
    if (num2 != 0) {
        int quotient = num1 / num2;
        printf("The quotient of %d and %d is %d\n", num1, num2, quotient);
    } else {
        printf("Whoops! Cannot divide by 0\n");
    }

    // Get the remainder of dividing the first number by the second number
    int remainder = num1 % num2;
    printf("The remainder of dividing %d by %d is %d\n", num1, num2, remainder);

    printf("Thanks for doing some math with me!\n");

    return 0;
}
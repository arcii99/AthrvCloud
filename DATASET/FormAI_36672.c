//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

int main() {

    printf("Welcome to my program!\n\n");

    printf("This program will perform a series of arithmetic operations on two numbers.\n");

    float num1, num2;

    printf("\nEnter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Addition
    float sum = num1 + num2;
    printf("\n%0.2f + %0.2f = %0.2f\n", num1, num2, sum);

    // Subtraction
    float diff = num1 - num2;
    printf("%0.2f - %0.2f = %0.2f\n", num1, num2, diff);

    // Multiplication
    float product = num1 * num2;
    printf("%0.2f * %0.2f = %0.2f\n", num1, num2, product);

    // Division
    if(num2 == 0) {
        printf("Cannot divide by zero.");
    } else {
        float quotient = num1 / num2;
        printf("%0.2f / %0.2f = %0.2f\n", num1, num2, quotient);
    }

    printf("\nThank you for using my program!");

    return 0;
}
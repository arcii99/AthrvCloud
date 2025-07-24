//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;

    printf("Welcome to the Arithmetic Calculator!\n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    printf("\nCalculating...\n\n");

    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, difference);
    printf("%d * %d = %d\n", num1, num2, product);
    printf("%d / %d = %d\n", num1, num2, quotient);
    printf("%d %% %d = %d\n", num1, num2, remainder);

    printf("\nThanks for using the Arithmetic Calculator!");

    return 0;
}
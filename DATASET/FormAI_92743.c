//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
// Hey there! Welcome to my awesome arithmetic example program written in C!
#include <stdio.h>

int main() {
    // First, let's declare some variables
    int number1, number2, sum, difference, product, quotient, remainder;

    // Now let's get some input from the user
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    // Time to perform some arithmetic operations!
    sum = number1 + number2;
    difference = number1 - number2;
    product = number1 * number2;
    quotient = number1 / number2;
    remainder = number1 % number2;

    // Let's show the user the results
    printf("\n");
    printf("%d + %d = %d\n", number1, number2, sum);
    printf("%d - %d = %d\n", number1, number2, difference);
    printf("%d * %d = %d\n", number1, number2, product);
    printf("%d / %d = %d\n", number1, number2, quotient);
    printf("%d %% %d = %d\n", number1, number2, remainder);
    printf("\n");

    // Time to celebrate our successful program execution!
    printf("Hurray! We have successfully performed arithmetic operations on two numbers!\n");

    return 0;
}
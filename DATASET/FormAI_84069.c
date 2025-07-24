//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>

int main() {

    // Initializing variables
    int num1 = 5;
    int num2 = 10;
    int sum = 0;
    int product = 0;
    float quotient = 0;
    int remainder = 0;

    // Adding two numbers
    sum = num1 + num2;

    // Printing addition result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    // Multiplying two numbers
    product = num1 * num2;

    // Printing multiplication result
    printf("The product of %d and %d is %d\n", num1, num2, product);

    // Dividing two numbers
    quotient = (float)num1 / num2;

    // Printing division result
    printf("The quotient of %d and %d is %.2f\n", num1, num2, quotient);

    // Finding remainder
    remainder = num2 % num1;

    // Printing remainder
    printf("The remainder of %d divided by %d is %d\n", num2, num1, remainder);

    return 0;
}
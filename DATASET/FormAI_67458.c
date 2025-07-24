//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>

int main() {
    printf("Welcome to the arithmetic program!\n");

    int input1, input2, sum, product, quotient, difference;

    printf("Please enter the first integer: ");
    scanf("%d", &input1);

    printf("Please enter the second integer: ");
    scanf("%d", &input2);

    sum = input1 + input2;
    product = input1 * input2;

    printf("\nCalculating sum and product...\n\n");

    printf("The sum of %d and %d is: %d\n", input1, input2, sum);
    printf("The product of %d and %d is: %d\n\n", input1, input2, product);

    printf("Now, let's perform some more operations.\n\n");

    quotient = input1 / input2;
    difference = input1 - input2;

    printf("The quotient when %d is divided by %d is: %d\n", input1, input2, quotient);
    printf("The difference between %d and %d is: %d\n\n", input1, input2, difference);

    printf("Thank you for using the arithmetic program!\n");

    return 0;
}
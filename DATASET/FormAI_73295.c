//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Welcome to the silly arithmetic program!\n");
    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\n\nHold on tight, we're about to do some math magic!\n");

    printf("\n\nThinking...\n\n");

    printf("Calculating...\n");

    int sum = num1 + num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    printf("\n\nWe did it! The results are in! \n\n");

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient of %d divided by %d is %d\n", num1, num2, quotient);
    printf("The remainder of %d divided by %d is %d\n", num1, num2, remainder);

    printf("\n\nWow, who knew arithmetic could be so funny?\n\n");

    return 0;
}
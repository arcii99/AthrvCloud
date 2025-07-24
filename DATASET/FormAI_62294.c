//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, product;
    float quotient;

    printf("Let's do some arithmetic!\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    product = num1 * num2;

    if (num2 != 0) {
        quotient = (float) num1 / num2;
    }

    printf("\n****** RESULTS ******\n");
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, product);

    if (num2 != 0) {
        printf("The quotient of %d and %d is %.2f\n", num1, num2, quotient);
    } else {
        printf("Sorry, can't divide by zero!\n");
    }

    printf("\nThanks for doing some arithmetic with me!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float quotient;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // perform addition operation
    sum = num1 + num2;

    // perform subtraction operation
    diff = num1 - num2;

    // perform multiplication operation
    prod = num1 * num2;

    // perform division operation
    quotient = (float) num1 / num2;

    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference of %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    printf("Quotient of %d and %d is %.2f\n", num1, num2, quotient);

    return 0;
}
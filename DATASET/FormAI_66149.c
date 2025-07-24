//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float quo;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // addition
    sum = num1 + num2;
    printf("Sum of %d and %d is %d\n", num1, num2, sum);

    // subtraction
    diff = num1 - num2;
    printf("Difference between %d and %d is %d\n", num1, num2, diff);

    // multiplication
    prod = num1 * num2;
    printf("Product of %d and %d is %d\n", num1, num2, prod);

    // division
    if(num2 == 0) {
        printf("Cannot divide by zero\n");
    }
    else {
        quo = (float)num1 / num2;
        printf("Quotient of %d and %d is %.2f\n", num1, num2, quo);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include<stdio.h>

int main() {
    int num1, num2, sum, diff, product;
    float quotient;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    product = num1 * num2;

    if (num2 == 0) {
        printf("Cannot divide by zero!\n");
    }
    else {
        quotient = (float)num1 / num2;
        printf("Quotient is %.2f\n", quotient);
    }

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, product);

    return 0;
}
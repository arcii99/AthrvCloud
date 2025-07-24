//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product;
    float quotient;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;

    if (num2 == 0) {
        printf("\nError! Division by zero.");
    } else {
        quotient = (float)num1 / num2;
        printf("\nQuotient: %f", quotient);
    }

    printf("\nSum: %d", sum);
    printf("\nDifference: %d", difference);
    printf("\nProduct: %d", product);

    return 0;
}
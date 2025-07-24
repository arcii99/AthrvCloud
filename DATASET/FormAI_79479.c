//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod, quotient, remainder;

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    printf("\nResults:\n");
    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", diff);
    printf("Product = %d\n", prod);
    printf("Quotient = %d\n", quotient);
    printf("Remainder = %d\n", remainder);

    return 0;
}
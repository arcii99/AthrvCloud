//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
    int num1, num2, num3, sum, product, quotient, remainder;
    float average;

    printf("Enter 3 integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    sum = num1 + num2 + num3;
    product = num1 * num2 * num3;
    quotient = num1 / num2;
    remainder = num1 % num2;
    average = (float)sum / 3;

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Quotient of num1 and num2: %d\n", quotient);
    printf("Remainder of num1 and num2: %d\n", remainder);
    printf("Average: %.2f\n", average);

    return 0;
}
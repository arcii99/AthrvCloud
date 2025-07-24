//FormAI DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float div;

    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    div = (float)num1 / num2;

    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", diff);
    printf("Product = %d\n", prod);
    printf("Quotient = %.2f\n", div);

    if(num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if(num1 < num2) {
        printf("%d is less than %d\n", num1, num2);
    } else {
        printf("%d and %d are equal\n", num1, num2);
    }

    if(num1 % 2 == 0) {
        printf("%d is even\n", num1);
    } else {
        printf("%d is odd\n", num1);
    }

    if(num2 >= 0) {
        printf("%d is positive\n", num2);
    } else {
        printf("%d is negative\n", num2);
    }

    return 0;
}
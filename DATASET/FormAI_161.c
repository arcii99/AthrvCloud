//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

int main() {

    int num1, num2, sum, difference, product, quotient, remainder;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    printf("\nResults:\n");
    printf("Sum         : %d\n", sum);
    printf("Difference  : %d\n", difference);
    printf("Product     : %d\n", product);
    printf("Quotient    : %d\n", quotient);
    printf("Remainder   : %d\n", remainder);

    if(num1 > num2) {
        printf("\n%d is greater than %d\n", num1, num2);
    }
    else if(num1 < num2) {
        printf("\n%d is less than %d\n", num1, num2);
    }
    else {
        printf("\nThe two numbers are equal\n");
    }

    return 0;

}
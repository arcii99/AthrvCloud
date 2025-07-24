//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
    int a, b, result;
    float float_dividend, float_divisor, float_result;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    result = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, result);

    result = a - b;
    printf("The difference between %d and %d is: %d\n", a, b, result);

    result = a * b;
    printf("The product of %d and %d is: %d\n", a, b, result);

    if (b == 0) {
        printf("The second number cannot be zero!\n");
    } else {
        result = a / b;
        printf("The quotient of %d divided by %d is: %d\n", a, b, result);

        float_dividend = a;
        float_divisor = b;
        float_result = float_dividend / float_divisor;
        printf("The result of %d divided by %d is: %f\n", a, b, float_result);
    }

    return 0;
}
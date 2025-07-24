//FormAI DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>

int main() {
    int a, b, sum, diff, prod;
    float quotient;

    printf("Enter two integers:\n");

    scanf("%d %d", &a, &b);

    sum = a + b;
    diff = a - b;
    prod = a * b;
    quotient = (float) a / b;

    printf("Sum of %d and %d is %d\n", a, b, sum);
    printf("Difference between %d and %d is %d\n", a, b, diff);
    printf("Product of %d and %d is %d\n", a, b, prod);
    printf("Quotient of %d and %d is %.2f\n", a, b, quotient);

    return 0;
}
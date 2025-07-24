//FormAI DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod, quo, mod;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    mod = num1 % num2;

    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference of %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    printf("Quotient of %d and %d is %d\n", num1, num2, quo);
    printf("Modulus of %d and %d is %d\n", num1, num2, mod);

    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if (num2 > num1) {
        printf("%d is greater than %d\n", num2, num1);
    } else {
        printf("%d and %d are equal\n", num1, num2);
    }

    int i, j, k;
    printf("Enter three integers: ");
    scanf("%d %d %d", &i, &j, &k);

    if (i > j && i > k) {
        printf("%d is the largest integer\n", i);
    } else if (j > i && j > k) {
        printf("%d is the largest integer\n", j);
    } else {
        printf("%d is the largest integer\n", k);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include<stdio.h>

int main() {

    int num1, num2;
    int sum, diff, prod, quo, rem;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    rem = num1 % num2;

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);
    printf("The quotient of %d and %d is %d\n", num1, num2, quo);
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, rem);

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main()
{
    int num1, num2, sum, diff, prod, mod;
    float div;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    div = (float)num1 / (float)num2;
    mod = num1 % num2;

    printf("\n-----Results-----\n");
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference between %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    printf("Division of %d by %d is %.3f\n", num1, num2, div);
    printf("Modulus of %d and %d is %d\n", num1, num2, mod);

    if (num1 > num2)
    {
        printf("%d is greater than %d\n", num1, num2);
    }
    else if (num2 > num1)
    {
        printf("%d is greater than %d\n", num2, num1);
    }
    else
    {
        printf("Both numbers are equal.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Scientific ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int sum = num1 + num2;
    int diff = num1 - num2;
    int product = num1 * num2;
    double quotient = (double) num1 / num2;
    int remainder = num1 % num2;
    double power = pow(num1, num2);

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient of %d and %d is %lf\n", num1, num2, quotient);
    printf("The remainder of %d divided by %d is %d\n", num1, num2, remainder);
    printf("%d raised to the power of %d is %lf\n", num1, num2, power);

    return 0;
}
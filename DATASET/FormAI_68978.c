//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, sum, diff, prod, quo, rem;
    float square_root, num_log;

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    rem = num1 % num2;

    printf("\nSum: %d", sum);
    printf("\nDifference: %d", diff);
    printf("\nProduct: %d", prod);
    printf("\nQuotient: %d", quo);
    printf("\nRemainder: %d", rem);

    square_root = sqrt(sum);
    printf("\nSquare root of sum: %f", square_root);

    num_log = log(num2);
    printf("\nNatural logarithm of second integer: %f", num_log);

    return 0;
}
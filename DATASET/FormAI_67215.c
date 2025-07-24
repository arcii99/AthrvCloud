//FormAI DATASET v1.0 Category: Arithmetic ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    printf("Enter two numbers: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int sum = num1 + num2;
    int diff = num1 - num2;
    int prod = num1 * num2;
    float quo = (float)num1 / (float)num2;

    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference of %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    printf("Quotient of %d and %d is %.2f\n", num1, num2, quo);

    printf("Square root of %d is %.2f\n", num1, sqrt(num1));
    printf("Log of %d to base e is %.2f\n", num1, log(num1));
    printf("Absolute value of %d is %d\n", diff, abs(diff));
    printf("Ceil of %.2f is %.0f\n", quo, ceil(quo));
    printf("Floor of %.2f is %.0f\n", quo, floor(quo));

    return 0;
}
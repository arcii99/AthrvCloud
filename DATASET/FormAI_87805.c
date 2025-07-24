//FormAI DATASET v1.0 Category: Math exercise ; Style: realistic
#include<stdio.h>
#include<math.h>

int main()
{
    int num1, num2;
    float answer, rounding;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    /* Find the square root of the first number */
    answer = sqrt(num1);
    printf("\nSquare root of %d is %.2f\n\n", num1, answer);

    /* Find the cube of the second number */
    answer = pow(num2, 3);
    printf("Cube of %d is %.2f\n\n", num2, answer);

    /* Find the rounding off answer of square root of first number */
    rounding = round(answer);
    printf("Rounding off value of square root of %d is %.2f\n\n", num1, rounding);

    /* Perform Trigonometric function (sine) on the second number */
    answer = sin(num2);
    printf("Sine of %d is %.2f\n\n", num2, answer);

    /* Calculate the exponential function of the second number */
    answer = exp(num2);
    printf("Exponential value of %d is %.2f\n\n", num2, answer);

    /* Find the log of first number (base 10) */
    answer = log10(num1);
    printf("Log value of %d is %.2f\n\n", num1, answer);

    return 0;
}
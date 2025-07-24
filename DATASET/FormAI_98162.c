//FormAI DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, result;

    printf("Enter the value of x: ");
    scanf("%f", &x);

    printf("Enter the value of y: ");
    scanf("%f", &y);

    /* Adding two numbers */
    result = x + y;
    printf("%.2f + %.2f = %.2f\n", x, y, result);

    /* Subtracting two numbers */
    result = x - y;
    printf("%.2f - %.2f = %.2f\n", x, y, result);

    /* Multiplying two numbers */
    result = x * y;
    printf("%.2f * %.2f = %.2f\n", x, y, result);

    /* Dividing two numbers */
    result = x / y;
    printf("%.2f / %.2f = %.2f\n", x, y, result);

    /* Finding the square root of a number */
    result = sqrt(x);
    printf("Square root of %.2f = %.2f\n", x, result);

    /* Finding the absolute value of a number */
    result = fabs(y);
    printf("Absolute value of %.2f = %.2f\n", y, result);

    /* Finding the power of a number */
    result = pow(x, y);
    printf("%.2f raised to the power of %.2f = %.2f\n", x, y, result);

    return 0;
}
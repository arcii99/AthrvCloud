//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, distance;

    printf("Enter the x coordinate of first point: ");
    scanf("%lf", &x1);

    printf("Enter the y coordinate of first point: ");
    scanf("%lf", &y1);

    printf("Enter the x coordinate of second point: ");
    scanf("%lf", &x2);

    printf("Enter the y coordinate of second point: ");
    scanf("%lf", &y2);

    distance = sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2)));

    printf("The distance between the two points is: %lf \n\n", distance);

    int num1, num2, sum, sub, mul, quo, rem;
    float div;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = (float)num1 / num2;
    quo = num1 / num2;
    rem = num1 % num2;

    printf("\nArithmetic operations performed on %d and %d are:\n", num1, num2);
    printf("Addition: %d + %d = %d\n", num1, num2, sum);
    printf("Subtraction: %d - %d = %d\n", num1, num2, sub);
    printf("Multiplication: %d * %d = %d\n", num1, num2, mul);
    printf("Division: %d / %d = %0.2f\n", num1, num2, div);
    printf("Quotient: %d / %d = %d\n", num1, num2, quo);
    printf("Remainder: %d %% %d = %d\n", num1, num2, rem);

    return 0;
}
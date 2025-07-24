//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include<stdio.h>

/* This program performs arithmetic calculations on 3 numbers entered by the user
   It also calculates the area of a rectangle using the lengths entered by the user
*/

int main() {
    int num1, num2, num3;
    float length, width, area;

    printf("Welcome to the Arithmetic Program\n");
    printf("Please enter three numbers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Addition
    int sum = num1 + num2 + num3;
    printf("\nThe sum of the three numbers is: %d\n", sum);

    // Subtraction
    int diff = num1 - num3;
    printf("The difference between %d and %d is: %d\n", num1, num3, diff);

    // Multiplication
    int product = num2 * num3;
    printf("The product of %d and %d is: %d\n", num2, num3, product);

    // Division
    float quotient = num2 / (float)num3;
    printf("The quotient of %d and %d is: %.2f\n", num2, num3, quotient);

    // Rectangle Area
    printf("\nNow let's calculate the area of a rectangle!\n");
    printf("Please enter the length in meters: ");
    scanf("%f", &length);
    printf("Please enter the width in meters: ");
    scanf("%f", &width);

    area = length * width;
    printf("The area of the rectangle is: %.2f square meters\n", area);

    return 0;
}
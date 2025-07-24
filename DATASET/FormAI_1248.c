//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    float power;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    //Performing Arithmetic Operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    power = pow(num1, num2);

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference of %d and %d is %d\n", num1, num2, difference);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient of %d and %d is %d\n", num1, num2, quotient);
    printf("The remainder of %d and %d is %d\n", num1, num2, remainder);
    printf("%d raised to power %d is %.2f\n", num1, num2, power);

    //Printing the operations using ASCII characters
    printf("\n\n\t\t+-------------+\n");
    printf("\t\t| Arithmetic  |\n");
    printf("+-------------+-------+--------+\n");
    printf("| Operation   |   %c   |  Value |\n", 37);
    printf("+-------------+-------+--------+\n");
    printf("| Addition    |   %c   |  %d    |\n", 43, sum);
    printf("| Subtraction |   %c   |  %d    |\n", 45, difference);
    printf("| Multiplication | %c   |  %d    |\n", 42, product);
    printf("| Division    |   %c   |  %d    |\n", 47, quotient);
    printf("| Remainder   |   %c   |  %d    |\n", 37, remainder);
    printf("| Power       |   %c   |  %.2f |\n", 94, power);
    printf("+-------------+-------+--------+\n");

    return 0;
}
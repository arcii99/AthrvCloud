//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float)num1 / num2;
    int remainder = num1 % num2;
    int factorial = 1;
    int i;
    for (i = 1; i <= num1; i++) {
        factorial *= i;
    }
    printf("\nThe sum of the two numbers is %d", sum);
    printf("\nThe difference between the two numbers is %d", difference);
    printf("\nThe product of the two numbers is %d", product);
    printf("\nThe quotient when the first number is divided by the second number is %.2f", quotient);
    printf("\nThe remainder when the first number is divided by the second number is %d\n", remainder);
    printf("\nThe factorial of the first number is %d\n", factorial);

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("Welcome to Torvalds Math! Please enter two integers:\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("\n");

    printf("Here are some calculations based on your numbers:\n");

    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    int difference = num1 - num2;
    printf("The difference between %d and %d is %d\n", num1, num2, difference);

    int product = num1 * num2;
    printf("The product of %d and %d is %d\n", num1, num2, product);

    printf("\n");

    printf("Now, let's perform some advanced calculations!\n");

    printf("\n");

    int power = num1;
    for (int i = 1; i < num2; i++) {
        power *= num1;
    }
    printf("%d raised to the power of %d is %d\n", num1, num2, power);

    int factorial = 1;
    for (int i = 1; i <= num1; i++) {
        factorial *= i;
    }
    printf("The factorial of %d is %d\n", num1, factorial);

    printf("\n");

    printf("Thank you for using Torvalds Math!\n");

    return 0;
}
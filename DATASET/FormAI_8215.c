//FormAI DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to our paranoid arithmetic program.\n");
    printf("We take the safety of our calculations seriously.\n\n");

    int firstNum, secondNum;

    printf("Please enter the first number: ");
    scanf("%d", &firstNum);

    printf("Please enter the second number: ");
    scanf("%d", &secondNum);

    int sum, difference, product, quotient, remainder;

    sum = firstNum + secondNum;
    difference = firstNum - secondNum;
    product = firstNum * secondNum;

    if (secondNum == 0) {
        printf("ERROR: Division by zero detected. Please enter a non-zero second number for division.");
        exit(1);
    } else {
        quotient = firstNum / secondNum;
        remainder = firstNum % secondNum;
    }

    printf("\nCalculations complete! Here are your results: \n");
    printf("The sum of %d and %d is: %d\n", firstNum, secondNum, sum);
    printf("The difference between %d and %d is: %d\n", firstNum, secondNum, difference);
    printf("The product of %d and %d is: %d\n", firstNum, secondNum, product);
    printf("The quotient of %d divided by %d is: %d\n", firstNum, secondNum, quotient);
    printf("The remainder of %d divided by %d is: %d\n", firstNum, secondNum, remainder);

    printf("\nThank you for using our paranoid arithmetic program. Have a safe day!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: happy
#include<stdio.h>

int main() {

    int num1, num2, sum, sub, mul, div;
    printf("I am a happy calculator program! Give me two numbers and I will do all fun calculations for you.\n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Addition operation
    sum = num1 + num2;
    printf("\nYay! The sum of %d and %d is: %d\n", num1, num2, sum);

    // Subtraction operation
    sub = num1 - num2;
    printf("\nHurray! The difference between %d and %d is: %d\n", num1, num2, sub);

    // Multiplication operation
    mul = num1 * num2;
    printf("\nWoohoo! The product of %d and %d is: %d\n", num1, num2, mul);

    // Division operation
    if(num2 != 0) {
        div = num1 / num2;
        printf("\nAwesome! The quotient when %d is divided by %d is: %d\n", num1, num2, div);
    } else {
        printf("\nOh no! Division by zero is not possible...I am sorry.\n");
    }

    printf("\nI hope you had a great time! Please come again for more fun calculations.\n\n");

    return 0;
}